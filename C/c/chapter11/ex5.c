#include<stdio.h>



void split_time(long total_sec, int *hr, int *min, int *sec);

int main(void)
{
    int t, hr, min, sec;
    printf("Enter the number of seconds since midnight: ");
    scanf(" %d", &t); 
    split_time(t,  &hr, &min, &sec);
    printf("Hours: %d, min: %d, sec: %d\n", hr, min, sec);

    return 0;
}




void split_time(long total_sec, int *hr, int *min, int *sec)
{
    int temp;
    *min = total_sec/60;
    *hr = *min/60;
    temp = *min; 
    *min = temp - *hr*60;
    *sec = total_sec - *hr*60*60 - *min*60;
} 
    
