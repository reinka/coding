#include<stdio.h>

float polynomial(float x);

int main(void)
{
   float x;

   printf("Enter a value for x: ");
   scanf(" %f", &x);

   printf("3x⁵ + 2x⁴ - 5x³ - x² + 7x - 6 = %.2f\n", polynomial(x));

   return 0;
}

float polynomial(float x)
{
   return 3*x*x*x*x*x + 2*x*x*x*x - 5*x*x*x - x*x + 7*x - 6;
}

