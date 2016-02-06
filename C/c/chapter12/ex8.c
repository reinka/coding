#include <stdio.h>

void store_zeros(int a[], int n);

int main(void)
{
	int n = 3, a[] = {1, 2, 3}, *p = a;

	store_zeros(p, n);

	while(p < a+n)
		printf("%d ",*p++);
	printf("\n");

	return 0;
}

void store_zeros(int a[], int n)
{
	int *p = a;

	while(p<a+n)
		*p++ = 0;
}