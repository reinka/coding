#include <stdio.h>

#define N 3

double inner_product(const double *a, const double *b, int n);

int main(void)
{
	double a[N]={1, 2, 3}, b[N]={1, 2, 3}, *p = a, *q = b;

	printf("%f\n", inner_product(p, q, N));


	return 0;
}

double inner_product(const double *a, const double *b, int n)
{
	double product = 0;
	int count = 0; 

	while (count < n){
		product += *a++ * *b++;
		count++;
	}

	return product;
}