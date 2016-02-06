#include <stdio.h>
#define N 10

int main(void){
	int a[] = {5, 15, 34, 54, 14, 2, 52, 72}, *p = &a[0], *q = &a[N-1], temp;
	
	while(p<q){
		temp = *p;
		*p++ = *q;
		*q-- = temp;
	}

	*p = &a[0];
	*q = &a[N-1];
	
	for(p; p < q; p++)
		printf("%d", *p);

	return 0;
}