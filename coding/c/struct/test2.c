#include <stdio.h>

struct time
{
	int hh;
	int min;
	int ss;
};

struct date
{
	int dd;
	int mm;
	int yy;
};

struct timeAndDate
{
	struct time stime;
	struct date sdate;
};

int main(void)
{
	struct timeAndDate  event;

	printf("Enter a time (hh:mm:ss): \n");
	scanf("%d:%d:%d", &event.stime.hh, &event.stime.min, &event.stime.ss);

	return 0;
}