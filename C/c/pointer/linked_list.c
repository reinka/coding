#include <stdio.h>

int main(int argc, char const *argv[])
{
	struct entry
	{
		int				value;
		struct entry 	*next;
	};

	char c = 'c';
	const char * const charPtr = &c;

	struct entry n1, n2, n3, *list_pointer = &n1;
	//int 		 i;

	n1.value = 100;
	n2.value = 200;
	n3.value = 300;

	n1.next = &n2;
	n2.next = &n3;
	n3.next = (struct entry *) 0;

	while ( list_pointer != (struct entry *) 0){
		printf("%d\n", list_pointer->value);
		list_pointer = list_pointer->next;
	}


	//i = n1.next->value; // i = (*(n1.next)).value innere klammer redundant
	//printf("%d \n", i);

	return 0;
}