//Function to determin if a character is alphabetic

#include <stdio.h>
#include <stdbool.h>

bool alphabetic (const char c);
int countWords (const char string[]);

int main(void)
{
	const char text1[]="Well, here goes.";
	const char text2[]="And here we go...again.";

	printf("%s - words = %d\n", text1, countWords(text1));
	printf("%s - words = %d\n", text2, countWords(text2));

	return 0;
}

bool alphabetic (const char c)
{
	if ( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return true;
	else
		return false;
}

int countWords (const char string[])
{
	int i, wordCount = 0;
	bool lookingForNewWord = true;

	for( i = 0; string[i] != '\0'; i++)
		if (alphabetic(string[i]))
		{
			if(lookingForNewWord)
				{
					++wordCount;
					lookingForNewWord = false;
				}
		}
		else
			lookingForNewWord = true;

	return wordCount;
}