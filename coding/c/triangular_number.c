/* 	Program to calculate the 200th triangular number */

#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n, triangularNumber;

	triangularNumber = 0;

	for(n = 1; n <= 200; n = n+1)
		triangularNumber = triangularNumber + n;

	printf("The 200th triangular numer is: %d\n", triangularNumber);

	printf("%2d\n", 8);
	return 0;
}