#include <stdio.h>

int main(void) {

	//i auch hier überflüssig da nicht relevant für den algorithmus
	int x = 7, j = 3/*i = 0*/;
	printf("zeile 1\n");
	do{
	printf("zeile 2\n");

	if (j%4)
		printf("zeile 3\n");
	/*--i;
	  ++i;
	*/
	j-=3;
	}while(/*(i +*/5/*)*/ < x + 10 && j> -50);
	printf("zeile 4\n");

	return 0;
}

