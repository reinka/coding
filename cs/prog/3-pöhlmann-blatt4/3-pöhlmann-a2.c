/*
n Programm in welchem die Variable int n mit einem Wert > 1
initialisiert ist. Geben Sie alle Zahlen zwischen 1 und n aus wobei abwechselnd von Unten hinauf und von Oben herab gezählt werden soll
*/

#include <stdio.h>

int main()
{
	int n = 35, first_half = 1, second_half = n, i = 1;
	
	while(i <= n){
		if(i%2)
		  printf("%d\n", first_half++);
		else
		  printf("%d\n", second_half--);
		i++;
	}
	
	return 0;
}	
