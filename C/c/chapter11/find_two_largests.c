#include <stdio.h>

void find_two_largest(int a[], int n, int *largest, int *second);

int main(void)
{
    int n = 5, a[n], largest, second;

    printf("Enter %d integers: ", n);
    for(int i = 0; i < n; i++)
	scanf("%d", &a[i]); 

    find_two_largest(a,n,&largest,&second);

    printf("Largest: %d\n2nd largest: %d\n", largest, second);

    return 0;
}



void find_two_largest(int a[], int n, int *largest, int *second)
{
    int temp;
    *largest = a[0];
    for(int i = 0; i < n; i++){
	if(a[0] < a[i]){
	  *largest = a[i];
	  temp = a[0];
	  a[0] = a[i];
	  a[i] = temp;
	}
    }
    *second = a[1];
    for(int i = 1; i < n; i++){
	if(*second < a[i])
	  *second = a[i];
     }
}

