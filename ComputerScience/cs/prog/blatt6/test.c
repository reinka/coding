#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int ran = rand()% 100 + 1;

	while(ran != 0){
		ran = rand () % 100 +1;
		printf("%d\n", ran);
	}

	return 0;
}