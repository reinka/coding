#include <stdio.h>
#define N 10

int main(void){
	int a[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, *p = &a[0], *q = &a[N-1], temp;
	
	while(p<q){
		temp = *p;
		*p++ = *q;
		*q-- = temp;
	}

	p = &a[0];
	q = &a[N];
	
	while(p<q)
		printf(" %d", *p++);
	printf("\n");

	return 0;
}