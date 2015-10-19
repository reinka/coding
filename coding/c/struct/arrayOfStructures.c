#include <stdio.h>

struct time
{
	int h;
	int min;
	int sec;
};

struct time  timeUpdate(struct time *p);

int main(void)
{
	struct time  testTime[5] = {
		{11, 59, 59}, {12, 0, 0}, {1, 29, 59}, 
		{23, 59, 59}, {19, 12, 27}
	};

	struct time *p = testTime;

	for(p = testTime; p < testTime + 5; p++){
		printf("Time is %.2d:%.2d:%.2d", (*p).h,
			(*p).min, (*p).sec);

		*p = timeUpdate(p);

		printf("...one second later it's %.2d:%.2d:%.2d\n",
			(*p).h, (*p).min, (*p).sec);
	}

	return 0;
}

struct time timeUpdate(struct time  *p)
{
	++(*p).sec;

	if((*p).sec == 60){ 		//next min
		(*p).sec = 0;
		++(*p).min;

		if ((*p).min == 60){   	//next hour 
			(*p).min = 0;
			++(*p).h;

			if((*p).h == 24)  	//midnight
				(*p).h = 0;	
		}
	}

	return (*p);
}