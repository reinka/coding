//Function to concatenate two character arrays
#include <stdio.h>

void concat(char result[], const char str1[], const char str2[])
{
	int i = 0, j = 0;

	//copy str1 to result

	while(str1[i] != '\0'){
		result[i] = str1[i];
		i++;
	}

	//copy str2 to result

	while(str2[j] != '\0'){
		result[i + j] = str2[j];
		j++;
	}

	result [i+j] = '\0';
}

int main(void)
{
	//void concat(char result[], const char str1[], int n1,
					//const char str2[], int n2);
	const char s1[] = "Hellu";
	const char s2[] = "Baby. Hru? Oo";
	char s3[20];

	concat(s3, s1, s2);

	for(int i = 0; s3[i] != '\0'; i++)
		printf("%c", s3[i]);

	printf("\n");

	return 0;
}