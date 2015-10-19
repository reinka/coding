#include <stdio.h>

#define N 5

void find_two_largest(const int a[], int n, int *largest, int *second);

int main(void)
{
    int a[N], largest, second, *p;

    printf("Enter %d integers: ", N);
    for(p = a; p < a + N; p++)
		scanf("%d", p); //evtl erst *p defnieren, der auf a zeigt
    

    find_two_largest(a,N,&largest,&second);

    printf("Largest: %d\n2nd largest: %d\n", largest, second);

    return 0;
}

void find_two_largest(const int *a, int n, int *largest, int *second)
{
	int count = 0, *p = a, *q;

	if( *p > *(p + 1)){
		*largest = *p;
		*second = *(p + 1);
	}
	else {
		*largest = *(p+1);
		*second = *(p);
	}

	while(p + 2 < p + n){
		if(*largest < *p){
			*second = *largest;
			*largest = *p++;
		}
		else if(*second < *p){
			*second = *p++;
		}
	}

}