// Program to update the time by one second

#include <stdio.h>

struct time 
{
	int h;
	int min;
	int sec;
};

struct time timeUpdate (struct time  now);

int main(void)
{
	struct time currentTime, nextTime;

	printf("Enter the time (hh:mm:ss): ");
	scanf("%d:%d:%d", &currentTime.h, &currentTime.min, 
		&currentTime.sec);

	nextTime = timeUpdate(currentTime);

	printf("Updated time is %.2d:%.2d:%.2d\n", nextTime.h,
		nextTime.min, nextTime.sec);

	return 0;
}

struct time timeUpdate(struct time  now)
{
	++now.sec;

	if(now.sec == 60){ 			//next min
		now.sec = 0;
		++now.min;

		if (now.min == 60){   	//next hour 
			now.min = 0;
			++now.h;

			if(now.h == 24)  	//midnight
				now.h = 0;	
		}
	}

	return now;
}