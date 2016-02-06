#include <stdio.h>
#include <stdlib.h>

int main()
{
	double a = 2.23e14;
	float b = 0.034;
	char c = 'C';
	unsigned int d = 3147483647;
	long e = 31474836472;
	{ int sd = 234; }
	int zero;
	
	printf("a=%f\nb=%f\nc=%c\nd=%u\ne=%ld. Sitz an einer 32-bit Maschine daher ist dieser Wert bei mir falsch :(\n", a, b, c, d, e);
	
	printf("c in Hex: %x\n", c);
	
	printf("a in Exp: %.2e\n", a);
	
	printf("b mit 10 Nachkommastellen: %.10f. Ups. Type float ist bisschen unpräzise.\n", b);
	
	printf("c mit 3 Stellen:%03d\n", c);
	
	printf("%d Ups, zero wurde ohne Wert deklariert -> undefined behaviour\n", zero);
	
	return 0;
}
