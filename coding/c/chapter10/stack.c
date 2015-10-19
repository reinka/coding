#include<stdbool.h>
#include<stdio.h>

#define STACK_SIZE 100

char contents[STACK_SIZE];
int top = 0;

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(char);
char pop(void);
void stack_overflow(void);
void stack_underflow(void); 

int main(void)
{
    char ch, temp; 
    int n = 0;
    printf("Enter a series of parenthesis and/or braces: ");
    while((ch = getchar())){
	n++;
	if((ch == '(') || (ch == '[') || (ch == '{'))
	    push(ch);
	else if((ch == ')') || (ch == ']') || (ch == '}')){
	    temp = pop();
	    if((ch == ')' && temp == '(') || (ch == ']' && temp == '[') || (ch == '}' && temp == '{'))
		;
	
	    else{
		printf("Parenthesis are not nested properly!\n");
		break;
	    }
	}
	    
	else if(ch == '\n' && is_empty()){
	    printf("Parenthesis are nested properly.\n");
	    break;
	}
	else if(ch == '\n' && !is_empty()){
	    printf("Parenthesis are not nested properly.\n");
	    break;
	}
	else{
	    printf("Parenthesis/braces ONLY, TURD!!! READ THE MOTHERFUCKIG INSTRUCTIONS\n");
	    break;
	}
    }

    return 0;
}

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

void stack_overflow(void)
{
   printf("Stack overflow");
   
}

void stack_underflow(void)
{
   printf("Stack underflow: Parenthesis are not nested properly.\n");
}

void push(char ch)
{
    if (is_full())
	stack_overflow(); 
    else
	contents[top++] = ch;
}

char pop(void)
{
    if (is_empty())
	stack_underflow();
    else
	return contents[--top];
}
