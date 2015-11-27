#include <stdio.h>
#include <stdlib.h>

int whichNumber(void)
{
	int n;
	printf("Die wievielte Fibanacci Zahl soll berechnet werden?\n");
	scanf(" %d", &n);

	return n;
}

int fibonacci(int n)
{
	int f_0 = 0, f_1 = 1;

	if (n > 1)
		return fibonacci(n - 1) + fibonacci(n - 2);
	else if (n == 1)
		return f_1;
	else if (n == 0)
		return f_0;

	else 
		return 1;
}
/* 
Fibonacci Zahl von 47 führt zu stack overflow. Iterative Funktion alternative Lösung.
long fib_iterative(int n){
	long int sum = 0, f_0 = 0, f_1 = 1;

	while(n-- > 1){
		sum = f_0 + f_1;
		f_0 = f_1;
		f_1 = sum;
	}
	return sum;
}
*/

int main(int argc, char const *argv[])
{
	printf("%d\n", fibonacci(whichNumber()));
	return 0;
}
