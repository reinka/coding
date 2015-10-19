#include<stdio.h>

#define N 10

void max_min(int a[], int n, int *max, int *min);

int main(void)
{

    int numbers[N], n = 0, big, small;

    printf("Enter %d integers: ", N);

    while(n<N)
	scanf(" %d", &numbers[n++]);

    max_min(numbers, n, &big, &small);

    printf("Largest: %d\nSmallest: %d\n", big, small);

    return 0;
}

void max_min(int a[], int n, int *max, int *min)
{   /* NOOB VARIANTE
    int temp; 
    
    for(int i = 0; i < N; i++){
	if(a[0] < a[i]){
	    temp = a[0];
	    a[0] = a[i];
	    *max = a[i];
    	}
    }

    for(int i = 0; i < N; i++){
	if(a[0] > a[i]){
	    temp = a[0];
	    a[0] = a[i];
	    *min = a[i];
        }
    }
    */

//GEILE VARIANTE

    *max = *min = a[0];
    for(int i = 0; i < n; i++){
	if( a[i] > *max)
	    *max = a[i];
	else if(a[i] < *min)
	    *min = a[i];
    }
}
