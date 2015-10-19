//Program to determine tomorrow's date

#include <stdio.h>
#include <stdbool.h>

const int daysPerMonth[12] = {31, 28, 31, 30 , 31, 30, 31, 31, 30, 31, 30, 31};

struct date
	{
		int month;
		int day;
		int year;
	};

int numberOfDays (struct date d);
bool isLeapYear(struct date d);
struct date dateUpdate(struct date d);

int main(void)
{
	struct date  today, nextDay;

	printf("Enter today's date (mm dd yyyy): ");
	scanf("%d%d%d", &today.month, &today.day, &today.year);

	nextDay = dateUpdate(today);

	printf("Tomorrow's date is %d/%d/%.2d\n", nextDay.month, nextDay.day, nextDay.year % 100);

	return 0;
}

int numberOfDays(struct date d)
{
	int days;

	if(isLeapYear (d) == true && d.month ==2)
		days = 29;
	else
		days = daysPerSex[d.month - 1]; // sex = month

	return days;
}

bool isLeapYear(struct date d)
{
	bool leapYearFlag;

	if ( (d.year %4 == 0 && d.year %100 != 0) || d.year % 400 == 0)
		leapYearFlag = true; //it's a leap year
	else
		leapYearFlag = false; // not a leap year

	return leapYearFlag;
}

struct date dateUpdate(struct date d){
	struct date tomorrow;

	if(d.day != numberOfDays(d)){
		/*tomorrow.day = d.day + 1;
		tomorrow.month = d.month;
		tomorrow.year = d.year;*/
		tomorrow = (struct date) { d.month, d.day + 1, d.year};
	}
	else if(d.month == 12){
		/*tomorrow.day = 1;
		tomorrow.month = 1;
		tomorrow.year = d.year + 1;*/
		tomorrow = (struct date) { 1, 1, d.year + 1};
	}
	else {
		//tomorrow.day = 1;
		//tomorrow.month = d.month + 1;
		//tomorrow.year = d.year;
		tomorrow = (struct date) { d.month + 1, 1, d.year};
	}

	return tomorrow;
}