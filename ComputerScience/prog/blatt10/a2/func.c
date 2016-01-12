#include "a2.h"

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