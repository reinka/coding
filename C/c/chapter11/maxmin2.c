#include<stdio.h>
#define N 10

void maxmin (int a[], int n, int *max, int *min);

int main(void){

    int b[N], i = N -1, big, small;

    printf("Enter %d integers: ", N);
    while(i >= 0)
	scanf(" %d", &b[i--]);
    

    maxmin(b, N, &big, &small);

    printf("Largest: %d\nSmallest: %d ", big, small);
    printf("\n");

    return 0;
}

void maxmin(int a[], int n, int *max, int *min){

     //Brute force:

     int temp;
    
     for(int i = 0; i < n; i++){
	if(a[0] < a[i]){
	    temp = a[0];
	    a[0] = a[i];
	    a[i] = temp;
	    *max = a[0];
	}
	else 
	    *max = a[0];
    }

    for(int i = 0; i < n; i++){
	if(a[0] > a[i]){
	    temp = a[0];
	    a[0] = a[i];
	    a[i] = temp;
	    *min = a[0];
	}
	else
	   *min = a[0];

    } 

    //elegante Variante:

    /**max = *min = a[0];
    for(int i = 1; i < n; i++){
	if(a[i] > *max)
	  *max = a[i];
	else if(a[i] < *min)
	  *min = a[i];
    }*/
}
