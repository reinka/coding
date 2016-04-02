
# coding: utf-8

# In[3]:

from sklearn import datasets
import numpy as np
import pandas as pd
get_ipython().magic('matplotlib inline')


# In[4]:

iris = datasets.load_iris()


# In[5]:

X = iris.data[:, [2,3]]
y = iris.target


# In[6]:

np.unique(y)


# #### split data set further into training and test set

# In[7]:

from sklearn.cross_validation import train_test_split
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=0)


# #### feature scaling our data by standardizing it

# In[8]:

from sklearn.preprocessing import StandardScaler
sc = StandardScaler()
sc.fit(X_train)
X_train_std = sc.transform(X_train)
X_test_std = sc.transform(X_test)


# #### train a perception model

# In[9]:

from sklearn.linear_model import Perceptron
ppn = Perceptron(n_iter=40, eta0=0.1, random_state=0)
ppn.fit(X_train_std, y_train)


# #### make prediction

# In[10]:

y_pred = ppn.predict(X_test_std)
print('Misclassified samples: %d' % (y_test != y_pred).sum())


# In[11]:

from sklearn.metrics import accuracy_score
print('Accuracy: %.2f' % accuracy_score(y_test, y_pred))


# # Testing on Titanic data set using age
# 
#     perceptron algorithm never converges on datasets that aren't perfectly linearly separable, 
#     which is why the use of the perceptron algorithm is typically not recommended in practice

# In[10]:

train_url = "http://s3.amazonaws.com/assets.datacamp.com/course/Kaggle/train.csv"
test_url = "http://s3.amazonaws.com/assets.datacamp.com/course/Kaggle/test.csv"
train = pd.read_csv(train_url)
test = pd.read_csv(test_url)
train.head()


# In[11]:

train_df = pd.DataFrame([train["Age"].fillna(train["Age"].mean()),train["Fare"], train["Survived"]])
train_df = train_df.transpose()
train_df.head()
train_df['Age'].head()


# In[12]:

X_train_titanic, X_test_titanic, y_train_titanic, y_test_titanic = train_test_split(np.array(train_df["Age"]).reshape(-1,1), 
                                                                                    np.array(train_df["Survived"]).reshape(-1,1), 
                                                                                    test_size=0.3, 
                                                                                    random_state=0)


# In[13]:

sc2 = StandardScaler()
sc2.fit(X_train_titanic)
train_fare_std = sc2.transform(X_train_titanic)
test_fare_std = sc2.transform(X_test_titanic)


# In[24]:

titanic_ppn = Perceptron(n_iter=25, eta0=.01, random_state=0)
titanic_ppn.fit(train_fare_std, y_train_titanic.ravel())


# In[25]:

titanic_pred = titanic_ppn.predict(test_fare_std)
print('Misclassified samples: %d' % (y_test_titanic.ravel() != titanic_pred).sum())
print("Accuracy score: %.2f" %accuracy_score(y_test_titanic.ravel(),titanic_pred))


# In[12]:

from decision_regions_with_test_samples import (plot_decision_regions,plt)
X_combined_std = np.vstack((X_train_std, X_test_std))
y_combined = np.hstack((y_train, y_test))
plot_decision_regions(X=X_combined_std,
                      y=y_combined,
                      classifier=ppn,
                      test_idx=range(105,150))
plt.xlabel('petal length [standardized]')
plt.ylabel('petal width [standardized]')
plt.legend(loc='upper left')
plt.show()


# ### Logistic Regression

# In[13]:

from sklearn.linear_model import LogisticRegression
lr = LogisticRegression(C=1000.0, random_state=0)
lr.fit(X_train_std, y_train)


# In[14]:

plot_decision_regions(X_combined_std, y_combined, classifier=lr, test_idx=range(105,150))
plt.xlabel("petal length [standardized]")
plt.ylabel("petal width [standardized]")
plt.show()


# In[17]:

lr.predict_proba(X_test_std[0,:])


# ### Support Vector Machine

# In[18]:

from sklearn.svm import SVC
svm = SVC(kernel='linear', C=1.0, random_state=0)
svm.fit(X_train_std, y_train)
plot_decision_regions(X_combined_std, y_combined, classifier=svm, test_idx=range(105,150))
plt.xlabel("petal length [standardized]")
plt.ylabel("petal width [standardized]")
plt.show()


# In[ ]:



