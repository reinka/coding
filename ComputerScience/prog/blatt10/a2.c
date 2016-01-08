#include <stdio.h>
#include <iso646.h>  
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define START 2

long number_of_chars(const char *argv)
{
	return strlen(argv); 
}

void encrypt(char * converse, const char *argv)
{
	char *endptr;
	long val = strtol(argv, &endptr, 10);

	if (val >= 26 || val <= -26)
		val %= 26; 

	/*argv zeigt hier auf zunaechst auf 'key'-Adresse,
	  muss daher angepasst werden, um auf das 2. Argument zu zeigen*/
	argv+= strlen(argv) + 1;
	for(int i = 0; i < strlen(argv); i++){
			*converse++ = (*(argv + i) + val);
	}
}

int main(int argc, char const *argv[])
{	
	int count = number_of_chars(argv[START]);
	char *converse = (char*) calloc(count, sizeof(char));
	char *free_ptr = converse;

	if(argc < 2){
		puts("Falsche Eingabe. Nicht genuegend Argumente. Tschuess.\n");
		exit(EXIT_FAILURE);
	}
	if(atoi(argv[1])){
		for(int i = 0; i < strlen(argv[START]); i++){
		//alternativ: argv[START][i] >= 'A' and argv[START][i] <= 'Z'
			if(isupper(argv[START][i])){
				puts("Falsche Eingabe. Nur Kleinbuchstaben erlaubt. Tschuess.\n");
				exit(EXIT_FAILURE);
			}
		}
	}
	else{
		puts("Falsche Key Eingabe. Tschuess.\n");
		exit(EXIT_FAILURE);
	}

	encrypt(converse,argv[1]);
	
	converse = free_ptr	;

	for(int i = 0; i <= count; i++)
		printf("%c", *converse++);
	puts(" ");

	free(free_ptr);
	

	return 0;
}

/*Es wurde nicht erkannt ob die passende Anzahl an Argumente eingegeben wurde.*/