#include <stdio.h>

int main(void) {
	//variable i in diesem fall überflüssig da diese konstant 0 bleibt
	int x = 7, j = 3/*, i = 0;*/; 
	printf("zeile 1\n");
	while(/*(i + */5/*)*/ < x + 10 && j > -50){
		printf("%d\n", j);
		printf("zeile 2\n");
		if(j%4)
		  printf("zeile 3\n");
		//--i;
		//++i;
		j-=3;
	}

	printf("zeile 4\n");

	return 0;
}

//Program liese sich optimieren indem i weggelassen werden würde, und die Bedingung der schleife nur j > -50 beinhaltete
//ja
//ja
