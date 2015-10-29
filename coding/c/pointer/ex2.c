#include <stdio.h>

struct entry {
	int value;
	struct entry *p;
}l1, l2, l3, l4, l5;

void insertEntry (struct entry *neu, struct entry *after)
{
	struct entry *temp = *neu;
	*neu = *after;
	*after = temp;
	
	/*neu->p = after->p;
	after->p = neu;
	*/
}

/*
void removeEntry (struct entry *after)
{
	after->p = ((after->p) -> p);
}
*/

void removeEntry (struct entry **after)
{
	struct entry *temp = *after;
	printf("%p and %p and %p\n", *after, *after, (*temp).p);
	(*after) = (*temp).p;
}

int main(int argc, char const *argv[])
{
	struct entry neu, *list_pointer = &l1;

	l1.value = 1;
	l1.p = &l2;

	l2.value = 2;
	l2.p = &l3;

	l3.value = 3;
	l3.p = &l4;

	l4.value = 4;
	l4.p = &l5;

	l5.value = 5;
	l5.p = (struct entry *) 0;

	neu.value = 100;
	neu.p = &neu;
	printf("l1.p = %p, l2.p = %p, l3.p = %p, neu.p = %p, list_pointer = %p\n", l1.p, l2.p, l3.p, neu.p, list_pointer);
	

	insertEntry(&neu, list_pointer);

	while(list_pointer){
		printf("%d\n", list_pointer->value);
		list_pointer = list_pointer->p;
	}


	list_pointer = &l1;
	
	printf("Testing some stuff\n");
	printf("%d\n", list_pointer->value);

	printf("Deleting entry now.\n");
	//removeEntry(list_pointer);
	removeEntry(&l5.p);

	while(list_pointer){
		printf("%d\n", list_pointer->value);
		list_pointer = list_pointer->p;
	}


	return 0;
}#include <stdio.h>

struct entry {
	int value;
	struct entry *p;
}l1, l2, l3, l4, l5;

void insertEntry (struct entry *neu, struct entry *after)
{
	struct entry *temp = *neu;
	*neu = *after;
	*after = temp;
	
	/*neu->p = after->p;
	after->p = neu;
	*/
}

/*
void removeEntry (struct entry *after)
{
	after->p = ((after->p) -> p);
}
*/

void removeEntry (struct entry **after)
{
	struct entry *temp = *after;
	printf("%p and %p and %p\n", *after, *after, (*temp).p);
	(*after) = (*temp).p;
}

int main(int argc, char const *argv[])
{
	struct entry neu, *list_pointer = &l1;

	l1.value = 1;
	l1.p = &l2;

	l2.value = 2;
	l2.p = &l3;

	l3.value = 3;
	l3.p = &l4;

	l4.value = 4;
	l4.p = &l5;

	l5.value = 5;
	l5.p = (struct entry *) 0;

	neu.value = 100;
	neu.p = &neu;
	printf("l1.p = %p, l2.p = %p, l3.p = %p, neu.p = %p, list_pointer = %p\n", l1.p, l2.p, l3.p, neu.p, list_pointer);
	

	insertEntry(&neu, list_pointer);

	while(list_pointer){
		printf("%d\n", list_pointer->value);
		list_pointer = list_pointer->p;
	}


	list_pointer = &l1;
	
	printf("Testing some stuff\n");
	printf("%d\n", list_pointer->value);

	printf("Deleting entry now.\n");
	//removeEntry(list_pointer);
	removeEntry(&l5.p);

	while(list_pointer){
		printf("%d\n", list_pointer->value);
		list_pointer = list_pointer->p;
	}


	return 0;
}