
# coding: utf-8

# In[12]:

from sklearn import datasets
import numpy as np
import pandas as pd


# In[2]:

iris = datasets.load_iris()


# In[4]:

X = iris.data[:, [2,3]]
y = iris.target


# In[5]:

np.unique(y)


# #### split data set further into training and test set

# In[6]:

from sklearn.cross_validation import train_test_split
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=0)


# #### feature scaling our data by standardizing it

# In[7]:

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


# In[15]:

train_url = "http://s3.amazonaws.com/assets.datacamp.com/course/Kaggle/train.csv"
test_url = "http://s3.amazonaws.com/assets.datacamp.com/course/Kaggle/test.csv"
train = pd.read_csv(train_url)
test = pd.read_csv(test_url)
train.head()


# In[16]:

train_df = pd.DataFrame([train["Fare"].fillna(train["Fare"].mean()), train["Survived"]])
train_df = train_df.transpose()


# In[17]:

train_np = np.array(train_df[:712])
test_np = np.array(train_df[712:])
train_np.shape, test_np.shape


# In[ ]:



