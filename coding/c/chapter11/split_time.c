#include<stdio.h>

void split_time(long total_sec, int *h, int *min, int *sec);

int main(void)
{
    long total_sec;
    int  h, min, sec;

    printf("Enter number of seconds since midnight: ");
    scanf("%ld", &total_sec);

    split_time(total_sec, &h, &min, &sec);

    printf("Time: %.2d:%.2d and %.2d seconds\n", h, min, sec);

    return 0;
}

void split_time(long total_sec, int *h, int *min, int *sec)
{

    float temp;
    temp = total_sec / 3600.0;  
    *h = temp;
    *min = (temp - *h) * 60.0;
    temp = (temp - *h) * 60.0 - *min;  
    *sec = temp * 60.0;
}
    

    
