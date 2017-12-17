# -*- coding: utf-8 -*-
# License AGPL-3.0 or later (http://www.gnu.org/licenses/agpl.html).
import numpy as np
import pandas as pd

class LDA(object):
    def __init__(self, df, group):
        self.df = df
        self.group = [group]

    def compute_group_means(self, features=None):
        """Compute group means.

        Parameters
        ----------
        features : list of str
            String of list containing the features for which to compute
             the group means.

        Returns
        -------

        """
        df = self.df
        if features:
            df = df[features + self.group]

        self.group_means = df.dropna().groupby(self.group).mean()
        return self.group_means

    def mahalanobis(self, y, mu, cov=None):
        """Compute the mahalanobis distance.

        For a given observation y, compute its mahalanobis distance to the
        vector mu with respect to the covariance matrix V.

        Paramaters
        ----------
        y : np.array-like
            Some observation. Must be of same dimension as mu.

        mu : np.array-like
            Group mean vector.

        V : np.array-like
            Covariance matrix.

        Returns
        -------
            Mahalanobis distance.
        """
        if not hasattr(self, 'cov'):
            self.cov = self.compute_cov()
            self.cov_inv = np.linalg.inv(self.cov)

        return (y - mu).dot(self.cov_inv).dot(y - mu)

    def accuracy(self, y, y_hat):
        """Compute classification accuracy.

        Parameters
        ----------
        y : array-like
            True classes.

        y_hat : array-like
            Predicted classes.

        Returns
        -------
        accuracy : float
            Relative frequency of correct classifications.
        """
        return sum(y == y_hat) / y.size

    def compute_cov(self, features=None):
        """Return covariance matrix for given features.

        Parameters
        ----------
        features: list of str, optional
            List of features for which to return the
            corresponding covariance.

        Returns
        -------
        cov: pd.DataFrame
        """
        if not features:
            tmp = self.df.dropna()
        else:
            tmp = self.df[features + self.group].dropna()

        self.group_sizes = tmp.groupby(self.group, sort=False).count().T.iloc[
            0]
        self.group_sizes.name = 'group_sizes'
        self.n_groups = self.group_sizes.size
        n = len(tmp)

        c = tmp.groupby(self.group, sort=False).cov()
        self.c = c
        cov_mat = np.multiply(
            c.values.reshape(self.n_groups, - 1),
            self.group_sizes.values[:, np.newaxis] - 1).sum(axis=0) / \
                  (n - self.n_groups)
        self.tmp = tmp
        self.cov = pd.DataFrame(cov_mat.reshape(c.shape[1], c.shape[1]))
        self.cov_inv = np.linalg.inv(self.cov)

        return self.cov

    def partition(a):
        return {c: (a == c).nonzero()[0] for c in np.unique(a)}