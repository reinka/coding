from math import sqrt

def not_modulo_three(n):
	not_modulo = True
	if(n%3==0):
		not_modulo = False
	return not_modulo

def nth_triangle(x):
	sum = 0
	for i in range(1, x+1):
		sum += i
	return sum

def list_factors(x):
	array = []
	for i in range(1,x+1):
		if not x%i:
			array.append(i)
	return array

def first_triangle_number(n):
	array = []
	triangle_numbers = []
	x = 1
	while(len(array)<n):
			#if(x%2 == 0 and nth_triangle(x)%3 == 0):
			array = []
			array = list_factors(nth_triangle(x))
			if(len(array) == n):
				triangle_numbers.append(nth_triangle(x))
				return nth_triangle(x)
			else:
				x+=1
				print x
				
print len(list_factors(2016))

#print nth_triangle(2)
#print len(list_factors(nth_triangle(2)))
print len(list_factors(556875000))

#for i in range(1,150):
#	print i, first_triangle_number(i)
	#if(first_triangle_number(i) == None):
	#	print list_factors(i)
	#else:
	#	print "Anzahl divisors:", len(list_factors(nth_triangle(i)))
