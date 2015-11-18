import numpy as np
from collections import defaultdict

max_ = [[0]]
def collatz_sequence(n):
	array = []
	while(n>1):
		if(not n%2):
			n /=2
		else:
			n = 3*n + 1
		array.append(n)
	
	return array

	

z= 999999
a = []
while(z>0):
	a = collatz_sequence(z)
	if(len(max_[0]) < len(a)):
		max_.append(a)
		max_.remove(max_[0])
	z -= 1

print max_
print max(max_[0])