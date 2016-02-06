#include <stdio.h>

int main(void)
{
	int n;

	printf("Enter time in seconds which you want to have converted in hours, minutes and seconds: ");
	scanf("%d", &n);

	/*if(n%3600 != 0){
		//printf("%d %d\n", n / 3600, n%3600);
		if((n%3600)%60 != 0)
			printf("%dh,  %dmin and %d sec.\n", n/3600, n%3600/60, n%3600%60);
		else
			printf("%d h, %d min and %d sec\n", n/3600, n%3600/60, n%3600%60);
	}
	else*/

	printf("%d h, %d min and %d sec\n", n/3600, n%3600/60, n%3600%60);

	22:10:10 22:10:09
	22:10:10 22:09:10
	22:10:10 22:10:11

	if((*p).hh > (*q).hh) && (*p).mm > (*q).mm) (*p).ss > (*q).ss){
		n = ((*q).hh * 3600 + (*q).mm * 60 + (*q).ss) - ((*p).hh * 3600 + (*p).mm * 60 + (*p).ss);
	}


	return 0;
}


if((*p).hh >= (*q).hh){
		if((*p).mm >= (*q).mm){
			if((*p).ss <= (*q).ss){
				n = ((*p).hh * 3600 + (*p).mm * 60 + (*p).ss) - ((*q).hh * 3600 + (*q).mm * 60 + (*q).ss);
				n = 24 * 3600 - n;
			}
			else
		n = ((*q).hh * 3600 + (*q).mm * 60 + (*q).ss) - ((*p).hh * 3600 + (*p).mm * 60 + (*p).ss);
		}
		else
		n = ((*q).hh * 3600 + (*q).mm * 60 + (*q).ss) - ((*p).hh * 3600 + (*p).mm * 60 + (*p).ss);
	}