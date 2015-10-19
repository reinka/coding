#include<stdio.h>

int largest_element(int [], int n);
float average(int [], int n);
int amount_positiv(int [], int n);

int main(void)
{
   int n;


   printf("Enter amount of elements you want the array to contain: ");
   scanf(" %d", &n);
   int a[n];
   printf("Enter %d elements: ", n);
   for(int i = 0; i < n; i++)
	scanf(" %d", &a[i]);

   printf("Largest element: %d\n", largest_element(a, n));
   printf("Average of all elements: %f\n", average(a, n));
   printf("Amount of positive elements in a: %d\n", amount_positiv(a,n));
   
   return 0;
}

int largest_element(int a[], int n)
{
   int x;

   for(int i = 0; i < n; i++){
	if(a[0] < a[i]){
	    x = a[0];
	    a[0] = a[i];
	    a[i] = x;
	}
   }

   /*for(int i = 0; i < n; i++)
	printf("%d\n", a[i]);*/

   return a[0];
}

float average(int a[], int n)
{
   int sum = 0;
   for(int i = 0; i < n; i++)
	sum += a[i];

   return sum/n;
}

int amount_positiv(int a[], int n)
{
   int count = 0;
   for(int i = 0; i < n; i++){
	if(a[i] > -1)
	   count++;
   }

   return count;
}
