f = open("test.txt", "r+")

def remove_duplicates(x):
    lst = []
    
    for n in x:
    	if n not in lst:
    		lst.append(n)
    return lst

for i in remove_duplicates([1,2,3,4,5,5,6,7,888,8,8]):
	f.write(str(i) + "\n")

print f.readline(1)
print f.readline(2)
print f.readline(3)
f.close()