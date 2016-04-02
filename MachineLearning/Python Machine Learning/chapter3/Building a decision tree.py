
# coding: utf-8

# In[1]:

from sklearn import datasets 
from sklearn.tree import DecisionTreeClassifier
from sklearn.cross_validation import train_test_split
import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
get_ipython().magic('pylab inline')
pylab.rcParams['figure.figsize']=(12,8)


# In[2]:

iris = datasets.load_iris()
X = iris.data[:,[2,3]]
y = iris.target


# In[3]:

X_train, X_test, y_train, y_test = train_test_split(X,y, test_size=.3, random_state=0)


# In[4]:

from decision_regions_with_test_samples import plot_decision_regions
tree = DecisionTreeClassifier(criterion="entropy", max_depth=3, random_state=0)
tree.fit(X_train, y_train)
X_combined = np.vstack((X_train, X_test))
y_combined = np.hstack((y_train, y_test))
plot_decision_regions(X_combined, y_combined,
                      classifier=tree, test_idx=range(105,150))
plt.xlabel("petal length [cm]")
plt.ylabel("petal width [cm]")
plt.legend(loc="upper left")
pylab.rcParams['figure.figsize']=(12,8)


# In[9]:

from sklearn.tree import export_graphviz
export_graphviz(tree, out_file="tree.dot", feature_names=["petal length", "petal width"])


# ### use `dot -Tpng tree.dot -o tree.png` to convert the .dot file to .png

# In[8]:

from IPython.display import Image
Image("tree.png")


# In[ ]:



