#include<stdio.h>

int main(void){

    int i, j, *p;
    i = 5;
    p = &i;
  
    printf("%d\n", *p);

    j = *&i; // äquivalten zu j = i;

    return 0;
}