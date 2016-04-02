
# coding: utf-8

# In[1]:

from sklearn.tree import (DecisionTreeClassifier, export_graphviz)
from sklearn.cross_validation import train_test_split
from sklearn import 
import numpy as np
import pandas as pd
get_ipython().magic('pylab inline')


# In[2]:

train_url = "http://s3.amazonaws.com/assets.datacamp.com/course/Kaggle/train.csv"
test_url = "http://s3.amazonaws.com/assets.datacamp.com/course/Kaggle/test.csv"
train = pd.read_csv(train_url)
test = pd.read_csv(test_url)
train.head()


# In[ ]:



