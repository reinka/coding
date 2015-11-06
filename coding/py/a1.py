import math

global n 
n = 3

def isPrime(x):
	if(x == 0 or x == 1):
		prime = False
	else:
		prime = True

	if(not(x % 2) and not 2):
			prime = False
			return prime

	for num in range(2, int(math.sqrt(x)+1)):
		if(x % num):
			prime = True
		else:
			prime = False
			return prime

	return prime

#Test isPrime(x)
#for num in range(0, 100):
#	print str(num) + ' ' + str(isPrime(num)) 



#Function calculating the biggest pandigital number with n digits
def biggest_pan(n):
	biggest = 0
	while(n > 0):
		 biggest += n*10**(n-1)
		 n -= 1

	return biggest

#Test biggest_num(n)
#print biggest_pan(n) 

#Function calculating the n-th digit of a number
def nth_digit(x, n):
	while(n > 0):
		num = x%10
		x /= 10
		n -= 1
	return num

#Test nth_digit(x,n)
#for num in range(1, n+1):
#	print nth_digit(biggest_pan(n), num)


#print isPrime(2143)

x = biggest_pan(n);

def main(x):
	while(x>0):
		if(isPrime(x)):
			for num in range(1, n+1):
				while((nth_digit(x,num) not in range(1,n+1))):
					x -= 1
			for dig in range(1, n+1):
					rest = x/10
					for j in range(1, n+1):
						if(nth_digit(rest,1) == dig):
							x-=1
							main(x)
						else:
							print x
							break
		else:
			x -= 1
			main(x)

	return x

print str(main(x)) + str(isPrime(main(x)))


