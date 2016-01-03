/*
 Schreiben Sie eine Funktion map welcher ein Array vom Typ int, die Länge des Arrays und ein Funktionspointer übergeben wird. Der Funktionspointer soll auf eine Funktion verweisen welche ein int als Parameter übernimmt und int zurück liefert.
Ihre Funktion map soll für jedes Element des Arrays die übergebene Funkti- on aufrufen und den Rückgabewert statt des originalen Elements im Array speichern.
• Schreiben Sie drei Funktionen welche:
– die übergebene Zahl mit 2 multipliziert
– die übergebene Zahl quadriert
– die Wurzel der übergebenen Zahl berechnet
• Schreiben Sie ein kurzes Testprogramm welches diese drei Funktionen mit- tels map auf ein Array anwendet und geben Sie die Ergebnisse aus.
Beispiel: Ausgehend von einem Array mit den Werten 1,2,3,4,5 würde nach Aufruf der map Funktion und übergabe der Quadrierfunktion als Funktionspoin- ter folgendes im Array stehen: 1,4,9,16,25.
*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define N 5

void map(int *arr, int n, int (*fptr)(int))
{
	for(int i = 0; i < n;i++)
		*(arr+i) = fptr(*(arr+i));
}

int mul_2(int a)
{
	return a*2;
}
int square(int a)
{
	return a*a;
}
int square_root(int a)
{	
	return sqrt(a);
}

int main(int argc, char const *argv[])
{
	int arr[N], (*fptr1)(int) = mul_2, (*fptr2)(int) = square, (*fptr3)(int) = square_root, operation, count=5;
	bool keep_going = true;


	new_array: 
		printf("Geben Sie %d natürliche Zahlen ein, die in einem Array gespeichert werden:\n", N);
		while(count){
			scanf(" %d", &arr[N-count]);
			count--;
		} while(getchar() != '\n');

	while(keep_going){
		
		count = 5;

		printf("Wählen Sie eine Operation aus?");
		printf("\n1 = Multiplikation mit 2\n2 = quadrieren\n3 = Wurzel ziehen\n99 = Neues Array einlesen\n0 = Programm beenden\n");
		scanf(" %d", &operation); while(getchar() != '\n');

		switch(operation){
			case 0: keep_going = false; break;
			case 1: map(arr, N, fptr1); break;
			case 2: map(arr, N, fptr2); break;
			case 3: map(arr, N, fptr3); break;
			case 99: goto new_array; break;
			default: printf("Wrong input. Try again.\n");
		}
		
		printf("\n");
		while(count){
			printf("%d ", arr[N-count]);
			count--;
		}
		printf("\n");
	}

	return 0;
}