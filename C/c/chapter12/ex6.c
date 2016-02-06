#include <stdio.h>

int sum_array(const int a[], int n);

int main(void)
{
	int n = 3, a[]={1, 2, 3};// *p = a;

	//while(p < &a[3])
		printf("%d\n", sum_array(a, n));

	return 0;
}


int sum_array(const int a[], int n)
{
	int sum, *p = a;

	sum = 0;
	while(p < a + n)
		sum += *p++;
	return sum;
}