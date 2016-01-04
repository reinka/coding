/*Deklarieren Sie ein Array queue von ganzen Zahlen mit 100 Elementen. Implementieren
Sie mit diesem Array eine Queue1. Dazu müssen Sie folgende Funktionen
implementieren:*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



void enqueue(int arr[], int* lastElementIdx, int *length, int element);
int dequeue (int arr[], int* lastElementIdx, int *length);
void printQueue(const int arr[], int lastElementIdx);
void dynamic_array_reallocation(int * const arr, bool expand, int *length);



int main(int argc, char const *argv[])
{
	int lastElementIdx = -1, N = 10, *length = &N;		//Annahme Queue ist leer 
	int *queue = (int*) calloc(10, sizeof(int));
	int *free_pointer = queue;

	printf("Testprints:\n%d, %d, %d\n",				////Testausgabe
		queue[0], queue[N/2], queue[N-1]);  
	

	puts("\nprintQueue #1:\n");					//Queue printen, sollte leer sein, wegen Annahme
	printQueue(queue, lastElementIdx);

	puts("Array mit 39 Elementen auffüllen");
	for(int i = 1; i < 39; i++)					//Array auffüllen
		enqueue(queue, &lastElementIdx, length, i);

	puts("Inhalt des Arrays nach dem Auffuellen. 20. Stelle sollte mit Testwert 999999 versehen sein, da urspruengliche Laenge von 10 auf 20 verdoppelt wurde.");
	for(int i = 0; i < 20; i++)
		printf("%d ", queue[i]);
	puts("");

	puts("\nprintQueue #2:\n");					//Queue printen lassen
	printQueue(queue,lastElementIdx);
	
	puts("\nAusgabe von dequeue:");				// Array entqueuen
	while(lastElementIdx > -1)
		printf("%d ", dequeue(queue, &lastElementIdx, length));

	puts("\nInhalt des Arrays nach Dequeue bis N + 5:");
	for(int i = 0; i < N + 5; i++)
		printf("%d ", queue[i]);
	puts("");
	puts("Folglich nach Dequeue Array immer noch Platz fuer mind. 10 Elemente");


	puts("\n************\nVersuch bis N + 50 zu enqueuen. Max. Wert: 60");
	for(int i = 1; i <= N + 10; i++)
		enqueue(queue, &lastElementIdx, length, i);
	puts("Array sollte hier von 20 auf 40 schliesslich auf 80 Elemente verlaengert worden sein");
	printf("Test: 80. Element: %d\n", queue[81]);

	printf("printQueue vom Versuch:\n");
	printQueue(queue,lastElementIdx);
	
	puts("\nDequeue Ausgabe vom Versuch:\n");
	while(lastElementIdx > -1)
		printf("Elementposition: %d\n", dequeue(queue, &lastElementIdx, length));

	puts("");

	puts("\nTEST: Inhalt des Arrays nach Dequeue bis N + 60:");
	for(int i = 0; i < N + 60; i++)
		printf("%d ", queue[i]);
	puts("");

	puts("*******************");

	for(int i = 1; i <= N + 50; i++)
		enqueue(queue, &lastElementIdx, length, i);
	puts("Kuerzen des Arrays auf n/2:");
	while(lastElementIdx > N/2)
		printf("%d ", dequeue(queue, &lastElementIdx, length));
	
	puts("");

	free(free_pointer);
	return 0;
}

void dynamic_array_reallocation(int *arr, bool expand, int *length)
{
	int new_size;
	if(expand){
		new_size = *length * 2;		
		arr = (int*) realloc(arr, sizeof(int) * new_size);
	}
	else{
		if(*length/2 > 10){
			new_size = *length / 2;
			arr = (int*) realloc(arr, sizeof(int) * new_size);
		}
		else{
			new_size = 10;
			arr = (int*) realloc(arr, sizeof(int) * new_size);
		}
	}

	printf("NEW SIZE %d\n", new_size);
	*length = new_size;
	arr[new_size-1] = 999999;  //wird jeweils am Ende des neuen Arrays angehaengt
}


/*
Übergabe von lastElementIdx als Pointer, damit dieser Wert nach Hinzufügen eines neuen
Elements upgedated werden kann. Konkret, um 1 erhöhen.
*/

void enqueue(int arr[], int* lastElementIdx, int *length, int element)
{
	if ( *lastElementIdx > *length){			  	//überprüft ob noch Platz im Array ist
		bool expand = true;						//falls nein, muss array expanidert werden
		dynamic_array_reallocation(arr, expand, length);
	}

	arr[*lastElementIdx + 1] = element;		//füge Element hinter lastElement ein 
		(*lastElementIdx)++;				//inkrementiere lastElementIdx
								
}


int dequeue (int arr[], int *lastElementIdx, int *length)
{
	int *p = NULL;
	const int pop = *arr; 					//auszugebendes Element

	if(*lastElementIdx > -1){			    //Überprüft, ob Element in Queue
		/*alle Elemente müssen um 1 aufrutschen.
		1. Fange dabei beim 1. Element an, und ersetze es durch das unmitelbar darauf folgende.
		2. Gehe zum nächsten Element und wiederhole Schritt 2 bis zum letzten Element, 
		da p+1 im letzten Fall außerhalb des Arrays liegt, und dadurch womöglich Komplikationen
		entstehen könnten */
		for(p = arr; p < arr + *lastElementIdx; p++){
				*p = *(p+1);		
		}
		//Position des letzten Elements muss um 1 verringert werden.
		(*lastElementIdx)--;

		/*ueberpruefung ob weniger als die haelfte des arrays belegt*/
		if(*lastElementIdx < *length/2){
			bool expand = false;
			dynamic_array_reallocation(arr, expand, length);
		}


		return pop;
	}

	return 0;
}



void printQueue(const int arr[], int lastElementIdx)
{
	while( lastElementIdx > -1){
		printf("%d\t", *(arr + lastElementIdx));
		lastElementIdx--;	
	}	
}