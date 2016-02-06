/*
Programm welches die Fibonacci Zahlen kleiner n iterativ
berechnet und ausgibt.
*/

#include <stdio.h>

int main()
{
	int n = 25, sum = 0, a = 0, b = 1;
	
	while(a+b < n){
		sum = a + b;
		a = b;
		b = sum;
		printf("%d ", sum);
	}
	
	printf("\n");
	
	return 0;
}
