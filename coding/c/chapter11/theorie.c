#include<stdio.h>

int main(void)
{
    int i, *p;

    p = &i;  // = pointer assignment

    i = 1;
    printf("%d\n%d\n", i, *p);

    *p = 2;

    printf("%d\n%d\n", i, *p);

    int *q = 5;

    //printf("%d\n", *q);
 
    //*q = 5;

    printf("%d\n", *q);

    return 0;
}
