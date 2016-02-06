/* dynamically allocated array*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int max = 0, number, i = 0;
	double *ptr;

	puts("What is the maximum number of type double entries?");
	if(scanf("%d", &max) != 1){
		puts("Wrong input. Bye!\n");
		exit(EXIT_FAILURE);
	}

	ptr = (double*) malloc(max * sizeof(double));
	if(ptr == NULL){
		puts("Memory allocation failed. Goodbye.");
		exit(EXIT_FAILURE);
	}

	/* ptr now points to an array of max elements*/
	double * const free_ptr = ptr; // free_ptr used to free memory later on, so ptr can be used in loops etc


	puts("Enter the values (q to quit)");
	while( i < max && scanf(" %lf", ptr++) == 1 )
		++i;
	
	ptr=free_ptr;
	printf("Here are your %d entries\n", number=i);
	for(i = 0; i < number;i++){
		printf("%7.2f\n", *ptr++);
		if(i%7==6)
			putchar('\n');
	}

	if(i%7!=6)
		putchar('\n');

	puts("Done");
	free(free_ptr);

	return 0;
}