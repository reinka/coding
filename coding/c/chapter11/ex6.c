#include<stdio.h>

#define N 10

void find_two_largest(int a[], int n, int *largest, int *second_largest);

int main(void)
{
    int first, second, a[N];

    printf("Enter %d integers: ", N);
    for(int i = 0; i < N; i++)
	scanf(" %d", &a[i]);

    find_two_largest(a, N, &first, &second);

    printf("Largest element: %d\nSecond largest element: %d\n", first, second);

    return 0;

}

void find_two_largest(int a[], int n, int *largest, int *second_largest)
{
    int temp;
    
    for(int i = 0; i < n; i++){
	if(a[0] < a[i]){
	   temp = a[0];
	   a[0] = a[i];
	   *largest = a[0];
	   a[i] = temp;
      	}
    }

    *second_largest = a[1];
   for(int i = 1; i < n; i++){
	if(*second_largest < a[i])
	    *second_largest = a[i];
    }
}
