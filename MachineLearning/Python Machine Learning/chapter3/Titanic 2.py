
# coding: utf-8

# In[4]:

from sklearn.tree import DecisionTreeClassifier, export_graphviz
from sklearn.cross_validation import train_test_split
import numpy as np
import pandas as pd
get_ipython().magic('pylab inline')


# In[264]:

#train_url = "http://s3.amazonaws.com/assets.datacamp.com/course/Kaggle/train.csv"
#test_url = "http://s3.amazonaws.com/assets.datacamp.com/course/Kaggle/test.csv"
train = pd.read_csv("/Users/slackoverflow/stats/kaggle/titanic/cleaned_train.csv")
test = pd.read_csv("/Users/slackoverflow/stats/kaggle/titanic/cleaned_test.csv")
comb = pd.read_csv("/Users/slackoverflow/stats/kaggle/titanic/TitanicCleanedCombined.csv")


# In[71]:

train.isnull().sum()


# In[72]:

train["Embarked"].unique()


# #### Handling nominal data via mapping

# In[43]:

(train['Embarked'].unique())


# In[44]:

test = train.copy()


# In[53]:

def nominal_mapping(df, colname):
    class_mapping = {label:idx for idx,label in enumerate(df[colname].unique()) if type(label) is not float
    }
    return class_mapping
    
def map_column(df,colname):
    class_mapping = nominal_mapping(df,colname) 
    
    df[colname] = df[colname].map(class_mapping)
    
    print("Column \"{}\" of your data frame has been mapped using the following mapping: {}".format(colname,
                                                                                               class_mapping))


# #### Finally map the data

# In[51]:

map_column(test,"Embarked")
test["Embarked"].unique()


# #### Replace NaNs with sklearn's Imputer function

# In[49]:

def imputed_data(df, colname, strategy="mean"):
    from sklearn.preprocessing import Imputer
    imr = Imputer(missing_values="NaN", strategy=strategy, axis=0)
    imr = imr.fit(df[colname].reshape(-1,1))
    imputed_data = imr.transform(df[colname].values.reshape(-1,1))
    df[colname] = imputed_data
    print("Data has been imputed to \"{}\"".format(colname))

imputed_data(test,"Embarked","most_frequent")
test["Embarked"].unique()


# ## Using sci-kit learn LabelEncoder class instead
# 
#     Note that the fit_transform method is just a shortcut for calling fit and transform separately, and we can use the inverse_transform method to transform the integer class labels back into their original string representation 

# In[59]:

from sklearn.preprocessing import LabelEncoder

class_le = LabelEncoder()

#Make sure that there is no NaNs within the column you want transformed!!!
y = class_le.fit_transform(train["Sex"].values)
y[1:10], class_le.inverse_transform(y)[1:10] #Displaying first 10 values of each variable


# ### A learning algorithm will now assume that male is larger than female. Although this assumption is incorrect, the algorithm could still produce useful results. However, those results would not be optimal. 
# 
# ## To avoid this, use either sci-kits' "OneHotEncoder" or Pandas' `get_dummies` method

# In[255]:

#Pandas' get dummy even ignores NaNs
pd.get_dummies(train[["Sex", "Embarked"]]).head(1)


# In[274]:

train.head(1)


# In[288]:

X = pd.get_dummies(train[["PassengerId", "Pclass", "Sex", "Age", "SibSp",
                 "Parch", "Fare", "Embarked", "Title", "Surname", "Family.Size", "FamilyId2"]])

Test = pd.get_dummies(test[["PassengerId", "Pclass", "Sex", "Age", "SibSp",
                 "Parch", "Fare", "Embarked", "Title", "Surname", "Family.Size", "FamilyId2"]])


# ## Need same amount of features, so will use `get_dummies` on the combined data set from R, and do the split with R afterwards

# In[270]:

combined = pd.get_dummies(comb[["PassengerId", "Pclass", "Sex", "Age", "SibSp",
                 "Parch", "Fare", "Embarked", "Title", "Surname", "Family.Size", "FamilyId2"]])

pd.DataFrame.to_csv(combined,"/Users/slackoverflow/stats/kaggle/titanic/PyCombined")


# ## After splitting Data in R, load it back to Python

# In[315]:

TrainK = pd.read_csv("/Users/slackoverflow/stats/kaggle/titanic/PyTrain.csv")
TestK = pd.read_csv("/Users/slackoverflow/stats/kaggle/titanic/PyTest.csv")
print(TrainK.shape, TestK.shape)


# ## 
# 

# In[272]:




# In[424]:

X_train, X_test, y_train, y_test = train_test_split(TrainK.values,train["Survived"].values, test_size=.3, random_state=0)


# ## Regular Decision Tree

# In[422]:

from sklearn.metrics import accuracy_score
from sklearn.tree import DecisionTreeClassifier
from sklearn.cross_validation import cross_val_score

from sklearn.datasets import make_blobs
#X_train, y_train = make_blobs(n_samples=623, n_features=713, centers=100, random_state=0)



decision = DecisionTreeClassifier(criterion="gini", max_depth=None, random_state=0)
decision.fit(X_train, y_train)
y_pred = decision.predict(TestK)
#print('Misclassified samples: %d' % (y_test != y_pred).sum())
#print('Accuracy: %.2f' % accuracy_score(y_test, y_pred, normalize=True))
#print("Alternativ test accuracy:", decision.score(X_test, y_test))

#scores = cross_val_score(decision, X_train, y_train)
#scores.mean()   

submission(TestK, y_pred, name="RDTupdated.csv")


# ## Random Forest

# In[426]:

from sklearn.ensemble import RandomForestClassifier

rf = RandomForestClassifier(n_estimators=100, criterion="gini", 
                            max_depth=None, min_samples_split=1,random_state=0)
rf.fit(X_train, y_train)
y_pred = rf.predict(TestK)
print('Training accuracy:', rf.score(X_train, y_train))
print('Test accuracy:', rf.score(X_test, y_test))


#print('Misclassified samples: %d' % (y_test != y_pred).sum())


scores = cross_val_score(rf, X_train, y_train)
print(scores.mean())
submission(TestK, y_pred, name="ForestUpdatedGini.csv")


# ## Extremly Randomized Trees
#     this one led to .8134 in kaggle with training set splitted 70:30

# In[431]:

from sklearn.ensemble import ExtraTreesClassifier

ert = ExtraTreesClassifier(n_estimators=100, criterion="entropy", max_depth=None, min_samples_split=1,random_state=0)
ert.fit(X_train, y_train)
y_pred = ert.predict(TestK)
#print('Misclassified samples: %d' % (y_test != y_pred).sum())
print('Training accuracy:' , ert.score(X_train, y_train))
print('Test accuracy:' , ert.score(X_test, y_test))

scores = cross_val_score(ert, X_train, y_train)
print(scores.mean())

submission(TestK, y_pred, name="ERDupdate.csv")


# ## Logistic regression

# In[207]:

from sklearn.linear_model import LogisticRegression
LogisticRegression(penalty='l1')
lr = LogisticRegression(penalty='l1', C=0.1)
lr.fit(X_train, y_train)
print('Training accuracy:', lr.score(X_train, y_train))
print('Test accuracy:', lr.score(X_test, y_test))
print('Training accuracy:' , lr.score(X_train, y_train))


# #### Standardize all the data now and repeat

# In[428]:

from sklearn.preprocessing import StandardScaler
stdsc = StandardScaler()
X_train_std = stdsc.fit_transform(X_train)
X_test_std = stdsc.transform(X_test)

#repeat logistic linear regression now
lr_std = LogisticRegression(penalty='l1', C=0.1)
lr_std.fit(X_train_std, y_train)
print('Training accuracy:', lr_std.score(X_train_std, y_train))
print('Test accuracy:', lr_std.score(X_test_std, y_test))
#print('Training-Accuracy: %.2f' % accuracy_score(y_test, y_pred))




#use L2 penalty now
print("\nUsing L2 penalty mode:\n")
lr_std_l2 = LogisticRegression(penalty='l2', C=0.1)
lr_std_l2.fit(X_train_std, y_train)
y_pred = lr_std_l2.predict(TestK)
print('Training accuracy:', lr_std_l2.score(X_train_std, y_train))
print('Test accuracy:', lr_std_l2.score(X_test_std, y_test))
submission(TestK, y_pred, name="LogisticRegression.csv")


# In[175]:

export_graphviz(decision, out_file="regular_decision_tree_titanic.dot", 
                feature_names=None,filled=True, rounded=True, special_characters=True)


# # Visualisations

# In[178]:

from IPython.display import Image
Image('regular_decision_tree_titanic.png')


# # Prepare submission

# In[313]:

def submission(df,pred, name="TitanicKaggle.csv"):
    sub = pd.DataFrame(df["PassengerId"])
    sub["Survived"] = pred
    pd.DataFrame.to_csv(sub,name, index=False)
    return sub.head()


# In[296]:

z = y_pred.copy() 


# In[305]:

get_ipython().magic('pinfo pd.DataFrame.to_csv')


# In[310]:

type(pd.DataFrame(TrainK["PassengerId"]))


# In[318]:

TestK


# In[ ]:



