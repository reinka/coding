# License AGPL-3.0 or later (http://www.gnu.org/licenses/agpl.html).
import numpy as np
import pandas as pd


class LDA(object):
    def __init__(self, df, group):
        self.df = df
        self.group = [group]

    def compute_group_means(self, features=None, verbose=0):
        """Compute group means.

        Parameters
        ----------
        features : list of str
            String of list containing the features for which to compute
             the group means.

        verbose : bool, optional
            If 1 or True, the group mean vectors will be printed as DataFrame.

        Returns
        -------
        group_mean_vectors : pd.DataFrame
            DataFrame where each row corresponds to one group mean vector.
            Groups are indicated by the index.
        """
        df = self.df
        if features:
            df = df[features + self.group]

        self.group_mean_vectors = df.dropna().groupby(self.group).mean()

        if verbose:
            print("Group mean vectors:\n", self.group_mean_vectors)
        return self.group_mean_vectors

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

    def partition(self, a):
        """Partition array into its unique classes.

        This method takes an array as input and returns a dictionary
        that maps each unique value to its indices.

        Parameters
        ----------
        a : np.array
            Array which consists of numerical (int) classes.

        Returns
        -------
        Dictionary that maps each unique value of the array to its indices.
        """
        return {c: (a == c).nonzero()[0] for c in np.unique(a)}

    def compute_S_W(self, features=None, verbose=0):
        """Compute within-groups scatter matrix.

        A pxp within-groups scatter matrix is computed where p is the number
        of features being considered. Missing values will be dropped before
        computing the actual scatter matrix.

        .. math:: S_w = \\sum_{i=1}^c S_i

        with `S_i` being the scatter-matrix of each group G_i (with group
        size n_i):

        .. math:: S_i = \\sum_{x \in G_i}^n_i (x - \mu_i) * (x - \mu_i)^T

        and `m_i` the group mean vector:

        .. math:: \frac{1}{n_i} \\sum_{x \in G_i}^n_i x

        Parameters
        ----------
        features : list of str, optional
            If provided, computation is based only on a data subset consisting
            of the given features.

        verbose : bool, optional
            If 1 or True, the within-groups scatter matrix will be printed.

        Returns
        -------
        S_W : array-like
            Within-groups scatter matrix.
        """
        X, y = self.prepare_data(features)

        # number of features
        p = self.p = X.shape[1]

        # number of total obs
        self.n_total = len(y)

        # number of groups
        self.n_groups = np.unique(y).shape[0]

        self.S_W = np.zeros((p, p))
        self.group_mean_vectors = self.compute_group_means(features, verbose)

        for klass, mean_vec in self.group_mean_vectors.iterrows():
            #  Compute group mean difference x - mu_p
            dif = X[y == klass] - mean_vec.values.reshape(-1, )
            self.S_W += np.tensordot(dif, dif, axes=((0), (0)))

        if verbose:
            print('within-groups Scatter Matrix:\n', pd.DataFrame(self.S_W))

        return self.S_W

    def compute_S_B(self, features=None, verbose=0):
        """Compute between-groups scatter matrix.

        A pxp between-groups scatter matrix is computed where p is the number
        of features being considered. Missing values will be dropped before
        computing the actual scatter matrix.

        The computation is based on the following equation:

        .. math:: S_b = \\sum_{i=1}^c N_i * (\mu_i - \mu) * (\mu_i - \mu)^T

        where `c` is the number of classes, `mu_i` and `N_i` the mean and
        size of the respective classes and `mu` the overall mean.

        Parameters
        ----------
        features : list of str, optional
            If provided, computation is based only on a data subset consisting
            of the given features.

        verbose : bool, optional
            If 1 or True, the between-groups scatter matrix will be printed.

        Returns
        -------
        S_B : array-like
            Between-groups scatter matrix.
        """
        X, y = self.prepare_data(features)

        # number of features
        p = self.p = X.shape[1]

        self.group_mean_vectors = self.compute_group_means(features, verbose)
        overall_mean = self.overall_mean = np.mean(X, axis=0)

        self.S_B = np.zeros((p, p))
        for klass, mean_vec in self.group_mean_vectors.iterrows():
            n = X[y == klass, :].shape[0]
            mean_vec = mean_vec.values.reshape(4, 1)  # make column vector
            overall_mean = overall_mean.reshape(4, 1)  # make column vector
            self.S_B += n * (mean_vec - overall_mean).dot(
                (mean_vec - overall_mean).T)
        if verbose:
            print('between-groups Scatter Matrix:\n', pd.DataFrame(self.S_B))

        return self.S_B

    def solve(self, verbose=1):
        """Solve the generalized eigenvalue problem.

        Parameters
        ----------
        verbose

        Returns
        -------

        """
        if not hasattr(self, 'S_B'):
            self.compute_S_B(verbose=verbose)
        if not hasattr(self, 'S_W'):
            self.compute_S_W(verbose=verbose)

        eig_vals, eig_vecs = np.linalg.eig(
            np.linalg.inv(self.S_W).dot(self.S_B))

        if verbose:
            for i in range(len(eig_vals)):
                eigvec_sc = eig_vecs[:, i].reshape(4, 1)
                print('\nEigenvector {}: \n{}'.format(i + 1, eigvec_sc.real))
                print('Eigenvalue {:}: {:.2e}'.format(i + 1, eig_vals[i].real))

        self.eig_vals, self.eig_vecs = eig_vals, eig_vecs

    def prepare_data(self, features=None):
        """Prepare data by splitting it into X and y matrices.

        Rows with missing values will be droped.

        Parameters
        ----------
        features : list of str, optional
            If provided, data will be split into a subset of the given
            features.

        Returns
        -------
        X, y : np.array
            X : Matrix consisting of the dependent variables
            y : Vector containing the groups labels.
        """
        df = self.df.dropna()
        if features:
            df = self.df[features + self.group].dropna()

        self.X = df.drop(self.group, axis=1).values
        self.y = df[self.group].values.ravel()

        return self.X, self.y

    def compute_pooled_cov(self, features=None, verbose=0):
        """Compute pooled covariance matrix.

        Parameters
        ----------
        features : list of str, optional
            If provided, computation is based only on a data subset consisting
            of the given features.

        verbose : bool, optional
            If 1 or True, the within-groups scatter matrix might be printed.

        Returns
        -------
        S : array-like
            Pooled covariance matrix.
        """
        if not hasattr(self, 'S_W') or features:
            self.S_W = self.compute_S_W(features, verbose)

        self.cov = self.S_W / (self.n_total - self.n_groups)

        if verbose:
            print("Pooled covariance matrix:\n", pd.DataFrame(self.cov))

        return self.cov

    def sanity_check(self):
        """Sanity check for the solution of the eigenvalue problem."""
        if not hasattr(self, 'eig_vals'):
            raise AttributeError('No eigenvalues found. Please compute them '
                                 'first.')

        for i in range(len(self.eig_vals)):
            eigv = self.eig_vecs[:, i].reshape(4, 1)
            np.testing.assert_array_almost_equal(
                np.linalg.inv(self.S_W).dot(self.S_B).dot(eigv),
                self.eig_vals[i] * eigv,
                decimal=6, err_msg='', verbose=True)
        print('Sanity check passed.')
