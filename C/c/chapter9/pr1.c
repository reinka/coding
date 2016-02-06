#include<stdio.h>

void selection_sort(int [], int n);

int main(void)
{
   int n;

   printf("Enter the number of elements the array is going to consist of: ");
   scanf(" %d", &n);

   int a[n];

   printf("Enter %d integers: ", n);
   for(int i = 0; i < n; i++)
	scanf(" %d", &a[i]);

   selection_sort(a,n);
   printf("Sorted order: ");
   for(int i = 0; i < n; i++)
	printf("%d ", a[i]);

   printf("\n");

   return 0;
}

void selection_sort(int a[], int n)
{
   int less;
   for(int i = 0; i < n; i++){
	if(a[i] > a[n - 1]){
	   less = a[n-1];
	   a[n-1] = a[i];
	   a[i] = less;
	   selection_sort(a, n-1);
	}
   }
} 
