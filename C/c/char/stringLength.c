//Function to count the number of characters in a string

#include <stdio.h>

int stringLength(const char a[]);

int main(void)
{
	char a[] = {'c', 'a', 't', '\0'};

	printf("fa\0g%d\n",stringLength(a));

	return 0;
}

int stringLength(const char a[])
{
	int i = 0, count = 0;

	while(a[i++] != '\0')
		count++;

	return count;
}