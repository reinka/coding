#include "stdio.h"

extern void f2(void);
static void f1(void);
extern int zahl;

int main(int argc, char const *argv[])
{
	printf("Hier ist main, zahl = %d\n", zahl);
	f1();
	f2();
	return 0;
}

int zahl = 6;

static void f1(void){
	printf("Hier ist f1, zahl = %d\n", zahl);
}