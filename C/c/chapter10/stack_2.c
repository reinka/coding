#include<stdbool.h>

#define STACK_SIZE 100

char contents[STACK_SIZE];
int top = 0;

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(int);
int pop(void);

int main(void)
{
    char = ch; 
    int n = 0;
    printf("Enter a series of parenthesis and/or braces: ");
    while((ch = getchar()) != '\n'){
	contents[i] = ch;
	n++;
    }

    for(int i; i < n; i++){
	if(contents[i] == '(' || contents[i] == '[' || contents[i] == '{')
	    push(contents[i]);

void make_empty(void)
{
    top = 0;
}

bool is_empty(void)
{
    return top == 0;
}

bool is_full(void)
{
    return top == STACK_SIZE;
}

void push(char i)
{
    if (is_full())
	stack_overflow(); 
    else
	contents[top++] = i;
}

int pop(void)
{
    if (is_empty())
	stack_underflow();
    else
	return contents[--top];
}
