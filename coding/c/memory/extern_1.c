#include "stdio.h"

extern void f2(void);
static void f1(void);
extern int number;

int main(int argc, char const *argv[])
{
	printf("Here is my number , number = %d\n", number);
	f1();
	f2();
	return 0;
}

int number = 6;

static void f1(void){
	printf("Here is f1, number = %d\n", number);
}