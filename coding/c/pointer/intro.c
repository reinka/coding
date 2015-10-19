#include <stdio.h>

int main(void)
{
	struct date
	{
		int dd;
		int mm;
		int yy;
	} today ;

	struct date  *p = &today; 

	p->mm = 9;
	p->dd = 25;
	p->yy = 2015;

	printf("Today's dat is %.2d.%.2d.%.2d.\n", p->dd, p->mm, p->yy);

	return 0;
}