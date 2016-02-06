import numpy as np

arr = np.arange(11)
#print arr

arr2 = np.arange(12)
#print arr2

np.append(arr, arr2)

x = np.insert(arr, 1, 5)

y = np.vstack([np.arange(10,21), arr])
print y
print np.max(len(y))
test = np.arange(5)

for i in y:
	if np.max(len(i)) > len(test):
		dif = np.max(len(i)) - len(test)
		while(dif > 0):
			test = np.insert(test, test[0], 0)
			dif -= 1
print test

y = np.vstack([test, y])
print y