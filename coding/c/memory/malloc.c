#include "malloc.h"
#include "stdio.h"

/* can't use function call when initializing stattic
	or global variables! executable code such as assignment
	statments must be inside functions! 
*/
static int *p_wrong = (int*) malloc(sizeof(int)); //wrong!!!

//can be avoided for static variables inside functions though:
// split assignment and initialization!
void test(void){
	static int* p;
	p = (int*) malloc(sizeof(int));
}

int main(int argc, char const *argv[])
{
	int *pi = (int*) malloc(sizeof(int));

	/*
	1. Memory is allocated from the heap
	2. memory is not modified or otherwise cleared
	3. the first byte's address is returned
	4. if malloc is unable to allocate memory -> returns NULL
	*/

	//Checking for NULL value, in case of no memory allocation:

	if( pi != NULL){
		printf("memory allocated\n");
	}
	else{
		printf("no memory\n");
	}

	printf("%d\n", *pi);

	char *name;
	printf("Enter a name:");
	scanf('%s', name);			//wrong! memory for *name hasn't been allocated!


	//allocating 80 bytes for 10 doubles

	int number_of_doubles = 10;

	double *pd_wrong = (double*) malloc(number_of_doubles); //wrong! allocates only 10 bytes!

	//this is how it's done properly. use sizeof() whenever possible!!
	double *pd_right = (double*) malloc(number_of_doubles * sizeof(double));




	return 0;
}