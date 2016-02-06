#include <stdio.h>
#include <stdlib.h>


char menu(void)
{
    char operation;
    printf("\nWählen Sie eine Operation aus (a = addieren, s = substrahieren, m = multiplizieren, b = beenden): ");
    scanf(" %c", &operation);
    while (getchar() != '\n');
    if(operation == 'b')
        exit(0);
 
    return operation;
}

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

int mul(int a, int b)
{
    return a * b;
}

int getOperandsAndExecuteOperation(char function)
{
    int first_operand, second_operand;
 
        printf("Wählen Sie 2 Operanden: ");
        scanf(" %d %d", &first_operand, &second_operand);
        while (getchar() != '\n');
        switch(function) {
            case 'a':   return add(first_operand, second_operand);
            case 's':   return sub(first_operand, second_operand);
            case 'm':   return mul(first_operand, second_operand);
            default:    exit(0);
        }
 
        return 0;
}

void print(int a)
{
    printf("\nDas Ergebnis ist %d\n\n\n", getOperandsAndExecuteOperation(menu()));
}

int main(int argc, char const *argv[])
{
    int i = 1;
    while(i)
        print(i);
 
    return 0;
}