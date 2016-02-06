/****************************************************************************************************
 *Ich habe bei diesem Program etwas improvisiert. Zusätzlich wird der Spieler, sobald er 			*
 *die Zufallszahl richtig erraten hat, gefragt ob er weiterspielen möchte. Antwortet er mit y/Y, 	*
 *wiederholt sich das Spiel, mit einer anderen Antwort wird das Program beendet.					*
 ****************************************************************************************************/ 

#include <stdio.h>
#include <time.h> // um ein "seed" für die Generierung der Zufallszahl zu setzen 
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h> // für die toupper-Funktion


int main()
{
	srand(time(NULL));
	int random_number, a[3], count = 0, larger_or_smaller = 0;
	bool wrong_guess = true;
	char reply = 'Y';

	//Hier kommt die zusätzliche while-loop 
	while(reply == 'Y'){
		count = 0;
		wrong_guess = true;
		random_number = rand() % 100 + 1;
		printf("Der Computer hat eine Zufallszahl generiert. Wählen Sie 3 Zahlen: ");
	
		
		//Das Programm ab hier hätte bereits gereicht. Die Variablen count, wrong_guess, 
		//und random_number hätten somit nur einmal initialisiert werden müssen. Dies hätte
		//während der Deklaration geschehen können.
		while(wrong_guess){
			for(int i = 0; i < 3; i++)
				scanf(" %d", &a[i]);
	
			larger_or_smaller = 0;
			for(int i = 0; i < 3; i++){
				if(a[i] > random_number)
					larger_or_smaller++;
				else if(a[i] < random_number)
					larger_or_smaller--;
				else
					wrong_guess = false;
	
			}
			if(wrong_guess){
				if(larger_or_smaller > 0)
					printf("Die gesuchte Zahl ist kleiner\n");
				else if(larger_or_smaller < 0)
					printf("Die gesuchte Zahl ist größer\n");
				printf("Wählen Sie erneut: ");
			}
			count++;
		}
	
		printf("Glückwunsch. Die gesuchte Zahl war %d. Sie haben in %d Zügen gewonnen\nMöchten Sie noch eine Runde spielen? (Y/N) ", random_number, count);
		
		//Zusätzlicher input, der überprüft, ob weitergespielt werden will. 
		//Die toupper-Funktion wandelt Kleinbuchstaben dabei in Großbuchstaben um.
		scanf(" %c", &reply);
		reply = toupper(reply);
	}
	printf("Schade. Auf Wiedersehen.\n");

	return 0;
}