import numpy as np
from collections import defaultdict



d = defaultdict(list)
sammlung = [0]
mydict = defaultdict(list)
max_key = mydict[0]
def find_max(n):
	global max_key
	for key, value in mydict.items:
		print key, value
	for i in range(1, len(n)):
		if len(n[i][0]) > len(max_key):
			max_key = n[i][0]

	return len(max_key)

def collatz_sequence(n,x):
	temp = n
	array = []
	global mydict
	while(n>1):
		if(not n%2):
			n /=2
		else:
			n = 3*n + 1
		array.append(n)
		mydict[x].append(n)
		print array
		find_max(mydict)	
	return find_max(n)

#z= 13
#count = 0
#while(z>0):
#	d[z].append(collatz_sequence(z,count))
#	sammlung.append(collatz_sequence(z))
#	z -= 1
#	count+=1
for i in range(0, 5):
	mydict[i].append([1,2,3,4,5,5])
for key, value in mydict.items:
	print key, value

max_list = 0

print "********************"
print len(max_key)
print max_key