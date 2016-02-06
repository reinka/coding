#include <stdio.h>

struct date
{
	int day;
	int month;
	int year;
} date[1];

int N (struct date *p);
void day(int n);

int main (void)
{
	struct date *p = date;
	int i= 0; 

	printf("Enter the date of which you want to know which day it falls on (dd.mm.yyyy): ");
	scanf("%d.%d.%d", &date[i].day, &date[i].month, &date[i].year);
	p = date;

	day(N(p));

	return 0;
}

int N (struct date *p)
{

	int dif = 0;
		
	if((*p).month <= 1){
		(*p).year -= 1;
		(*p).month += 13;
	}
	else
		(*p).month += 1;

	dif += ((1461 * (*p).year) / 4 + (153 * (*p).month) /5 + (*p).day);

	return (dif - 621049);
}

void day(int n){

	n %= 7;

	switch(n){
		case 0: printf("Sunday\n"); break;
		case 1: printf("Monday\n"); break;
		case 2: printf("Tuesday\n"); break;
		case 3: printf("Wednesday\n"); break;
		case 4: printf("Thursday\n"); break;
		case 5: printf("Friday\n"); break;
		case 6: printf("Saturday\n"); break;
	}
}