#include<stdio.h>
#define STACK_SIZE 100

char contents[STACK_SIZE];

int main(void)
{
    char ch; 
    int i = 0;
    printf("Enter a series of parenthesis and/or braces: ");
    while((ch = getchar()) != '\n'){
	contents[i] = ch;
	i++;
    }

    for(int j = 0; j < i; j++)
	printf("%c", contents[j]);

    printf("\n");

    return 0;
}
