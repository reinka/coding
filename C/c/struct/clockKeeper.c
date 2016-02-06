#include <stdio.h>
#include <stdbool.h>

const int daysPerMonth[12] = {31, 28, 31, 30 , 31, 30, 31, 31, 30, 31, 30, 31};

bool newDay = false;

struct date
{
	int dd;
	int mm;
	int yy;
};

struct time
{
	int hh;
	int min;
	int ss;
};

struct dateAndTime
{
	struct date sdate;
	struct time stime;
};

struct dateAndTime clockKeeper (struct dateAndTime event);
struct time  timeUpdate(struct time stime);
struct date dateUpdate(struct date d);
int numberOfDays (struct date d);
bool isLeapYear(struct date d);

int main(void)
{
	struct dateAndTime  event;

	printf("\nEnter a date (dd.mm.yyyy) and time (hh:mm:ss):\nDate: ");
	scanf("%d.%d.%d", &event.sdate.dd, &event.sdate.mm, &event.sdate.yy);
	printf("Time: ");
	scanf("%d:%d:%d", &event.stime.hh, &event.stime.min, &event.stime.ss);

	event = clockKeeper(event);

	printf("\nOne second later:\n\n%.2d.%.2d.%.2d\n%.2d:%.2d:%.2d\nYou're welcome.\n\n", event.sdate.dd, event.sdate.mm, event.sdate.yy, event.stime.hh, event.stime.min, event.stime.ss );

	return 0;
}

struct dateAndTime clockKeeper (struct dateAndTime event)
{
	event.stime = timeUpdate(event.stime);

	if(newDay)
		event.sdate = dateUpdate(event.sdate);

	return event;
}

struct time timeUpdate(struct time  stime)
{
	++stime.ss;

	if(stime.ss == 60){ 		//next min
		stime.ss = 0;
		++stime.min;

		if (stime.min == 60){   	//next hour 
			stime.min = 0;
			++stime.hh;

			if(stime.hh == 24){  	//midnight
				stime.hh = 0;
				newDay = true;
			}
		}
	}

	return stime;
}

struct date dateUpdate(struct date d){
	struct date tomorrow;

	if(d.dd != numberOfDays(d)){
		/*tomorrow.day = d.day + 1;
		tomorrow.month = d.month;
		tomorrow.year = d.year;*/
		tomorrow = (struct date) { d.dd + 1, d.mm, d.yy};  //Compound
	}
	else if(d.mm == 12){
		/*tomorrow.day = 1;
		tomorrow.month = 1;
		tomorrow.year = d.year + 1;*/
		tomorrow = (struct date) { 1, 1, d.yy + 1};
	}
	else {
		//tomorrow.day = 1;
		//tomorrow.month = d.month + 1;
		//tomorrow.year = d.year;
		tomorrow = (struct date) {1, d.mm + 1, d.yy};
	}

	return tomorrow;
}

int numberOfDays(struct date d)
{
	int days;

	if(isLeapYear (d) == true && d.mm == 2)
		days = 29;
	else
		days = daysPerMonth[d.mm - 1];

	return days;
}

bool isLeapYear(struct date d)
{
	bool leapYearFlag;

	if ( (d.yy %4 == 0 && d.yy %100 != 0) || d.yy % 400 == 0)
		leapYearFlag = true; //it's a leap year
	else
		leapYearFlag = false; // not a leap year

	return leapYearFlag;
}