#include <stdio.h>
#include <stdlib.h>

/*
 *Function that reads text input one character at a time (getc)
 *and grows the string as needed using realloc
 */
char * readln(void) {

	char *line = NULL, *tmp = NULL;
	size_t size = 0, index = 0, chunk = 1;
	int ch = EOF;

	while(ch){
		ch = getc(stdin);

		/*check if we need to stop*/
		if(ch == '\n' || ch == EOF)
			ch = 0;

		/*check if we need to expand*/
		if(size <= index)
		{
			size += chunk;
			tmp = (char*) realloc(line, size*sizeof(char));
			if(!tmp)
			{
				free(line);
				line = NULL;
				break;
			}
			line = tmp;	
		}

		line[index++] = ch;
	}

	return line;
}
