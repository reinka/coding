#include <stdio.h>
#include <stdlib.h>
#define N 10

int main(int argc, char const *argv[])
{
	int *arr = (int*) calloc(sizeof(int), N);
	int a[5];

	printf("%lu, %lu\n", sizeof(arr)/sizeof(int), sizeof(a)/sizeof(int));

	while(arr != NULL)
		printf("%d\n", *arr++);

	return 0;

}