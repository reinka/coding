
# coding: utf-8

# In[248]:

from sklearn.tree import DecisionTreeClassifier, export_graphviz
from sklearn.cross_validation import train_test_split
import numpy as np
import pandas as pd
get_ipython().magic('pylab inline')


# In[256]:

train_url = "http://s3.amazonaws.com/assets.datacamp.com/course/Kaggle/train.csv"
test_url = "http://s3.amazonaws.com/assets.datacamp.com/course/Kaggle/test.csv"
train_df = pd.read_csv(train_url)
test_df = pd.read_csv(test_url)
train.head()


# In[250]:

train["Embarked"].unique(), train["Age"].unique()


# In[211]:

gender = [1.0 if i=='female' else 0.0 for i in train["Sex"]]
embarked = []
X = np.array([train["Age"].fillna(train["Age"].mean()),train["Fare"], 
                    gender, train["Pclass"]])
y = np.array(train["Survived"])
X = X.T


# In[212]:

X_train, X_test, y_train, y_test = train_test_split(X,y, test_size=.3, random_state=0)


# In[343]:

tits = DecisionTreeClassifier(criterion="entropy",max_depth=3, random_state=0)
tits.fit(X, y)


# In[344]:

y_final = tits.predict(final)
print('Misclassified samples: %d' % (y_test != y_pred).sum())


# In[321]:

from sklearn.metrics import accuracy_score
print('Accuracy: %.2f' % accuracy_score(y_test, y_pred))


# In[407]:

from IPython.display import Image
from sklearn.tree import export_graphviz
tree.export_graphviz(tits, out_file='titanic.dot',  
                         feature_names=["age", "fare", "gender", "pclass"],  
                         class_names=None,  
                         filled=True, rounded=True,  
                         special_characters=True)  
Image("titanic.png")


# In[260]:

gender_f = [1.0 if i=='female' else 0.0 for i in test_df["Sex"]]
final = np.array([test_df["Age"].fillna(test_df["Age"].mean()),test_df["Fare"], 
                    gender_f, test_df["Pclass"]]).T
final.shape


# In[278]:

fix = np.isnan(final[:,1])


# In[292]:

final[152,1] = (final[:151,1].sum() + final[153:,1].sum())/417


# In[297]:

solution = pd.DataFrame(test_df["PassengerId"])


# In[345]:

solution["Survived"] = y_final


# In[317]:

solution.head()


# In[330]:

solution.to_csv("python_titanic.csv", index=False)


# In[346]:

solution["Survived"].sum()


# In[350]:

solution2 = solution.copy()


# In[403]:

from sklearn.ensemble import RandomForestClassifier
clf = RandomForestClassifier(n_estimators=500, criterion="gini", n_jobs=4, random_state=2)
clf.fit(X,y)


# In[404]:

rf_final = clf.predict(final)


# In[405]:

solution2["Survived"] = rf_final
solution2["Survived"].sum()


# In[ ]:



