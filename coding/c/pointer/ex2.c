#include <stdio.h>

struct entry {
	int value;
	struct entry *p;
}l1, l2, l3;

void insertEntry (struct entry *neu, struct entry *after)
{
	/*struct entry *temp = *neu;
	*neu = *after;
	*after = temp;
	*/

	
	neu->p = after->p;  //bsp l1 = after 
	after->p = neu;
	
}

void removeEntry (struct entry *after)
{
	after->p = ((after->p) -> p);
}

int main(int argc, char const *argv[])
{
	struct entry neu, *list_pointer = &l1;

	l1.value = 1;
	l1.p = &l2;

	l2.value = 2;
	l2.p = &l3;

	l3.value = 3;
	l3.p = (struct entry *) 0;

	neu.value = 4;
	neu.p = &neu;	

	insertEntry(&neu, list_pointer);

	while(list_pointer){
		printf("%d\n", list_pointer->value);
		list_pointer = list_pointer->p;
	}

	printf("Deleting entry now.\n");

	list_pointer = &l1;
	
	printf("Testing some stuff\n");
	printf("%d\n", list_pointer->value);

	removeEntry(list_pointer);
	
	while(list_pointer){
		printf("%d\n", list_pointer->value);
		list_pointer = list_pointer->p;
	}


	return 0;
}