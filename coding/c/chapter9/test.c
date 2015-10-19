#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int dice(void);
int play(void);

int main(void)
{   
   printf("#7: dice 1 + dice 2: %d\nsum1 + sum2: %d\n", dice(), play());

   return 0;
}

int dice(void)
{
   int test, fuck;

   srand((unsigned) time(NULL));

	test = rand()%7; printf("#1: %d \n", test);
   	fuck = rand()%7; printf("#2: %d \n", fuck);
	printf("#3: %d %d\n", test, fuck);
	return test + fuck;
}

int play(void)
{
   int sum1, sum2;
   sum1 = dice(); printf("#4: %d \n", sum1);
   sum2 = dice(); printf("#5: %d \n", sum2);
   printf("#6: %d %d\n", sum1, sum2);
   return sum1+sum2;
}
