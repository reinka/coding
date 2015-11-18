import csv


with open('alt.txt') as inputfile:
	number = list(csv.reader(inputfile))

def get_number():
	for i in number:
		for a in i:
			return a

str_num = get_number()

#def get_numbers_starting_with_nine():
count = 0
num = 0
lst = []
for a in str_num:
	num+=1
	lst.append(str_num[count:count+13:])
	count += 1


print num
print lst
zeroless = []

for i in range(num):
	contains_zero = True
	for a in lst[i]:
		if a == str(0):
			contains_zero = False
	if(contains_zero):
		zeroless.append(lst[i])

print
print len(zeroless)

product_lst = []

for num in range(len(zeroless)):
	product = 1
	for char in zeroless[num]:
		product *= int(char)
	product_lst.append(product)

print product_lst

max_product = product_lst[0]
for num in range(len(product_lst)):
	if max_product < product_lst[num]:
		max_product = product_lst[num]
print max_product

