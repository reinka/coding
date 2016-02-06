//bla

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_SIZE_WORD 50

int main(int argc, char const *argv[])
{
	FILE *fp;
	char oneWord[MAX_SIZE_WORD], ch;

	if(argc == 1) {
		puts("You haven't entered the file name into the command line.");
		puts("Try again.");
		return EXIT_FAILURE;
	}
	
	puts("Choose n:");
	int n;
	while(scanf("%d%c", &n, &ch) != 2 || ch != '\n'){
		puts("Wrong input. Integer only:");
		while(getchar() != '\n')
			;
	}

	fp = fopen(argv[1], "r");
	if(!fp){
		puts("Error. File could not be opened. Goodbye.");
		return EXIT_FAILURE;
	}

	while((ch = fscanf(fp, "%s", oneWord)) && ch != EOF){
	
		int wordLen = strlen(oneWord);

		//checks for dots, comma, semicolon, etc.
		//at the end of the word
		if(!isalpha(oneWord[wordLen-1]))
			wordLen--;

		//number of N gramms = word length - (n-gramm length - 1)
		int numOfNgramm = wordLen - n + 1;
		
		if (wordLen >= n){
			int count = 0;
			printf("%s: %d Buchstaben\n", oneWord, wordLen);
			for (int i = 0; i < numOfNgramm; count++, ++i){	
				char temp[MAX_SIZE_WORD];
				strncpy(temp, &oneWord[i], n);
				temp[n] = '\0';
				printf("%s\n", temp);
			}printf("%d N-Gramme\n\n", count);
			//printf("%s, %d, %d\n", oneWord, wordLen, numOfNgramm);
		}

	}

	fclose(fp);

	return EXIT_SUCCESS;
}