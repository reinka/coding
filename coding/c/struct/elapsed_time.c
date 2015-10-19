#include <stdio.h>

struct time
{
	int hh;
	int mm;
	int ss;
}time1[2];

struct time elapsed_time(struct time *p, struct time *q);

int main(void)
{
	struct time *p = time1, *q = time1 + 1, n;
	int i = 0;

	printf("Enter 2 different times (hh:min:ss):\nTime #1: ");
	while(i < 2){
		scanf("%d:%d:%d", &time1[i].hh, &time1[i].mm, &time1[i].ss);
		if(i == 0)
			printf("Time #2: ");
		i++;
	}

	n = elapsed_time(p, q);

	printf("Elapsed time: %.2d hours, %.2d minutes and %.2d seconds\n", n.hh, n.mm, n.ss);

	return 0;
}

struct time elapsed_time(struct time *p, struct time *q)
{
	int n, x, y, z;
	struct time t;

	if(((*p).hh > (*q).hh) || ((*p).hh >= (*q).hh && (*p).mm > (*q).mm) || ((*p).hh >= (*q).hh && (*p).mm >= (*q).mm && (*p).ss > (*q).ss)){
		
		x = 23 - (*p).hh + (*q).hh;
		y = 59 - (*p).mm + (*q).mm;
		z = 60 - (*p).ss + (*q).ss;
		
		if(z > 59){
			y += z/60;
			z %=60;
		}
		
		if(y > 59){
			x += y/60;
			y %= 60;
		}
	}

	else{
		n = ((*q).hh * 3600 + (*q).mm * 60 + (*q).ss) - ((*p).hh * 3600 + (*p).mm * 60 + (*p).ss);
		
		x = n/3600;
		y = n%3600/60;
		z = n%3600%60;
	}

	
	(t).hh = x;
	(t).mm = y; 
	(t).ss = z;
	return t;
}