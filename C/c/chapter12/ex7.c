#include <stdio.h>
#include <stdbool.h>

#define N 3

bool search(const int a[], int n, int key);

int main(void)
{
	int a[N] = {1, 2, 3}, key;

	printf("Enter integer you wanna have the array searched for: ");
	scanf("%d", &key);

	if(search(a, N, key)==true)
		printf("The array contains at least one such element.\n");
	else
		printf("We're sorry, but the array doesn't contain any element of that kind\n");

	return 0;
}

bool search(const int a[], int n, int key)
{
	int *p = a, count = 0;

	while(p < a+N){
		if(*p++ == key)
			count++;
	}

	return count;
}
