#include<stdio.h>

int power(int x, int n);

int main(void)
{
   int n, x;

   printf("x to the power of n\n");
   printf("Choose x: ");
   scanf(" %d", &x);
   printf("Choose n: ");
   scanf(" %d", &n);

   printf("%d to the power of %d: %d\n", x, n, power(x, n));

   return 0;
}

int power(int x, int n)
{
   if(n == 0)
	return 1;
   else if(n % 2 == 0)
  	return power(x, n/2)*power(x,n/2);
   else if( n % 2 != 0)
	return x * power(x, n - 1);
}
