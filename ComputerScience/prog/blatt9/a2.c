/*Deklarieren Sie ein Array queue von ganzen Zahlen mit 100 Elementen. Implementieren
Sie mit diesem Array eine Queue1. Dazu müssen Sie folgende Funktionen
implementieren:*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 100



int enqueue(int arr[], int* lastElementIdx, int length, int element);
int dequeue (int arr[], int* lastElementIdx);
void printQueue(const int arr[], int lastElementIdx);



int main(int argc, char const *argv[])
{
	int queue[N], lastElementIdx = -1;				//Annahme Queue ist leer

	printf("Testprints:\n%d, %d, %d\n",				////Testausgabe
		queue[0], queue[49], queue[99]);  
	

	

	printf("\nprintQueue #1:\n");					//Queue printen, sollte leer sein, wegen Annahme
	printQueue(queue, lastElementIdx);

	for(int i = 1; i <= 100; i++)					//Array auffüllen
		enqueue(queue, &lastElementIdx, N, i);

	printf("\nprintQueue #2:\n");					//Queue printen lassen
	printQueue(queue,lastElementIdx);
	
	printf("\nAusgabe von dequeue:\n");				// Array entqueuen
	while(lastElementIdx > -1)
		printf("%d\t", dequeue(queue, &lastElementIdx));

	


	printf("\n************\nVersuch jenseits queue[N] zu enqueuen:\n");
	for(int i = 1; i <= 150; i++)
		enqueue(queue, &lastElementIdx, N, i);

	printf("\nprintQueue vom Versuch:\n");
	printQueue(queue,lastElementIdx);
	
	printf("\nDequeue Ausgabe vom Versuch:\n");
	while(lastElementIdx > -1)
		printf("%d\t", dequeue(queue, &lastElementIdx));



	
	return 0;
}

/*
Übergabe von lastElementIdx als Pointer, damit dieser Wert nach Hinzufügen eines neuen
Elements upgedated werden kann. Konkret, um 1 erhöhen.
*/

int enqueue(int arr[], int* lastElementIdx, int length, int element)
{
	if ( *lastElementIdx < length){			  	//überprüft ob noch Platz im Array ist
		arr[*lastElementIdx + 1] = element;		//falls ja, füge Element hinter lastElement ein 
		(*lastElementIdx)++;					//inkrementiere lastElementIdx
		return true;
	}
													
	return false;								//falls nein, return false
}


int dequeue (int arr[], int* lastElementIdx)
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