#include <stdio.h>

struct date
{
	int day;
	int month;
	int year;
} date[2];

int N (struct date *p);

int main (void)
{
	struct date *p = date;
	int i= 0; 

	printf("Enter both dates of which you want to know the elapsed time (dd.mm.yyyy):\n1st date: ");
	
	while(p < date + 2){
		scanf("%d.%d.%d", &date[i].day, &date[i].month, &date[i].year);
		p++;
		i++;
		if (i < 2)
			printf("2nd date: ");
	}

	p = date;

	printf("Elapsed time: %d days.\n", N(p));

	return 0;
}

int N (struct date *p)
{

	int dif = 0, count = 0;

	while(p < date + 2){
		
		if((*p).month <= 2){
			(*p).year -= 1;
			(*p).month += 13;
		}
		else
			(*p).month += 1;
	
		if (count == 0)
			dif -= ((1461 * (*p).year) / 4 + (153 * (*p).month) /5 + (*p).day);
		else
			dif += ((1461 * (*p).year) / 4 + (153 * (*p).month) /5 + (*p).day);
		
		count++;
		p++;
	}

	return dif;
}