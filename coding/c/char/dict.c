//Program that takes input and looks it up in the dictionary

#include <stdio.h>
#include <stdbool.h>

struct entry
{
	char  word[15];
	char definition[50];
};

bool equalStrings(const char s1[], const char s2[])
{
	int i = 0;
	bool areEqual;

	while(s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		++i;

	if (s1[i] == '\0' && s2[i] == '\0')
		areEqual = true;
	else
		areEqual = false;

	return areEqual;
};

//function to luook up a word inside a dict

int lookup (const struct entry  dict[], const char  search[], const int  entries)
{
	int i;

	for (i = 0; i < entries; i++)
		if(equalStrings(search, dict[i].word))
			return i;

	return -1;
};

int main(void)
{
	struct entry dictionary[100] = 
	{
		{"aardvark", 	"a burrowing African mammal"	},
		{"abyss", 		"a bottomless pit"				},
		{"acumen", 		"mentally sharp, keen"			}
	};

	char	word[10];
	int 	entries = 3, entry;

	printf("Enter word: ");
	scanf("%14s", word);
	entry = lookup(dictionary, word, entries);

	if(entry != -1)
		printf("%s\n", dictionary[entry].definition);
	else
		printf("Sorry, the word %s is not in my dictionary.\n", word);

	return 0;
}

int compareStrings(const char s1[], const char s2[])
{
	int i = 0, answer;

	while(s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;

	if(s1[i] < s2[i])
		answer = -1;
	else if(s1[i] > s2[i])
		answer = 1;
	else
		answer = 0;
}