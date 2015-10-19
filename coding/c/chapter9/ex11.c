#include<stdio.h>
#include<ctype.h>

float compute_GPA(char grades[], int n);

int main(void)
{
   int n;

   printf("Enter amount of grades you want to fill into an array: ");
   scanf(" %d", &n); 
   char grades[n];
   printf("Enter grades: ");
   for(int i = 0; i < n; i++)
	scanf(" %c", &grades[i]);
   
   printf("Average of the grades: %f\n", compute_GPA(grades, n));

   return 0;
}

float compute_GPA(char grades[], int n)
{
   int copy[n], sum = 0;

   //convert lowercase into uppercase letters
   for(int i = 0; i < n; i++){	
	if( grades[i] != toupper(grades[i]))
		grades[i] = toupper(grades[i]);
   }

   //convert grades into equivalent value
   for(int i = 0; i < n; i++){
	if(grades[i] == 'A')
		copy[i] = 4;
	else if(grades[i] == 'B')
		copy[i] = 3;
	else if(grades[i] == 'C')
		copy[i] = 2;
	else if(grades[i] == 'D')
		copy[i] = 1;
	else if(grades[i] == 'F')
		copy[i] = 0;
	//calculate sum
	sum += copy[i];
   }

   return sum/n; //average
}

 
