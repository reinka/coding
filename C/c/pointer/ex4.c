#include <stdio.h>

struct entry {
	int value;
	struct entry *p;
}l1, l2, l3, l4, l5;

//INSERT FUNCTION, USING POINTER ADDRESSES AS PARAMETERS
void insertEntry (struct entry **neu, struct entry **after)
{
	struct entry *temp = *neu;
	*neu = *after;
	*after = temp;
	

}

/***********************************************************
 	ALTERNATIVELY: PASSING POINTER INSTEAD OF ADDRESS.
 	THOUGH I COULDNT FIGURE OUT HOW TO INSERT AT THE FRONT
 	OF THE LIST. NOT SURE IF IT'S EVEN POSSIBLE WITH THIS 
 	METHOD.
  	
void insertEntry (struct entry *neu, struct entry *after){
	neu->p = after->p;
	after->p = neu;
}
*************************************************************/


//REMOVE FUNCTION, USING POINTER ADDRESSES AS PARAMETERS
void removeEntry (struct entry **after)
{
	struct entry *temp = *after;
	printf("%p and %p and %p\n", *after, *after, (*temp).p);
	(*after) = (*temp).p;
}

/***********************************************************
 	ALTERNATIVELY: PASSING POINTER INSTEAD OF ADDRESS.
 	THOUGH I COULDNT FIGURE OUT HOW TO REMOVE THE FIRST ITEM
 	OF THE LIST. NOT SURE IF IT'S EVEN POSSIBLE WITH THIS 
 	METHOD.
  	
void removeEntry (struct entry *after)
{
	after->p = ((after->p) -> p);
}
*************************************************************/


int main(int argc, char const *argv[])
{
	struct entry neu, *list_pointer = &l1; //POINTER TO THE BEGINNING OF THE LIST

	l1.value = 1;
	l1.p = &l2;

	l2.value = 2;
	l2.p = &l3;

	l3.value = 3;
	l3.p = &l4;

	l4.value = 4;
	l4.p = &l5;

	l5.value = 5;
	//NULL POINTER MARKING THE END OF THE LIST
	l5.p = (struct entry *) 0; 

	neu.value = 100;
	neu.p = &neu;

	printf("Testing some stuff\n");
	printf("l1.p = %p, l2.p = %p, l3.p = %p, neu.p = %p, list_pointer = %p\n", l1.p, l2.p, l3.p, neu.p, list_pointer);
	
	//INSWERT NEW LIST ENTRY, PASSING POINTER ADDRESS TO FUNCTION
	insertEntry(&neu.p, &list_pointer);

	while(list_pointer){
		printf("%d\n", list_pointer->value);
		list_pointer = list_pointer->p;
	}

	//SINCE neu WAS INSERTED TO THE LIST:
	list_pointer = &neu;

	printf("Deleting entry now.\n");

	//REMOVING 1ST LIST ENTRY, PASSING POINTER ADDRESS TO FUNCTION
	removeEntry(&neu.p);
	//IF YOU WANNA REMOVE ONE OF THE OTHER ENTRIES,
	//USE &l1.p, &neu.p, &l2.p, &l3.p, &l4.p

	while(list_pointer){
		printf("%d\n", list_pointer->value);
		list_pointer = list_pointer->p;
	}


	return 0;
}