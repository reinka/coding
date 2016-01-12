#include "a3.h"

int expandArray(int **arr, int length)
{
    /*function to double the array size*/
    
    int *temp, newLength = length * 2;
    
    length *= 2;
    temp = (int*) realloc(*arr, sizeof(int)*newLength);
    if (temp != NULL) {
        length = newLength;
        *arr = temp;
    }
    
    return length;
}

int shrinkArray(int **arr, int length, bool min)
{
    /*function that cuts array in half*/
    int *temp, newLength;
    
    if (min){
        newLength = 10;
    }
    else{
        newLength = length /= 2;
    }
    
    temp = (int*) realloc(*arr,sizeof(int)*newLength);
    if ( temp != NULL) {
        *arr = temp;
        length = newLength;
    }
    
    return length;
}

void enqueue(int **arr, int* lastElementIdx, int *length, int element)
{
    if ( *lastElementIdx < *length - 1){        //checks if there's space for another element
        (*arr)[*lastElementIdx + 1] = element;      //if yes, insert element after lastElementIdx
        (*lastElementIdx)++;                    //increment lastElementIdx
    }
    else{
        *length = expandArray(arr, *length);    //if not, expand array
    }
}



int dequeue (int **arr, int* lastElementIdx, int *length)
{
    int *p = *arr;
    if(*lastElementIdx > -1){               //Checks if there is an element in the queue
        if (*lastElementIdx + 2 < *length/2 and *lastElementIdx + 2 > 10) {
            bool min = false;
            *length = shrinkArray(arr, *length, min);
        }
        else if (*lastElementIdx + 2 == 10){
            bool min = true;
            *length = shrinkArray(arr, *length, min);
        }
        
        (*lastElementIdx)--;        //shift position of last element
        return *(p + *lastElementIdx + 1);
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


void test1(int **arr, int* lastElementIdx, int *length)
{
    int** temp = arr;
    printf("\nprintQueue #1:\n");                   //print queue, should be empty
    puts("(No elements)");
    printQueue(*temp, *lastElementIdx);
    
    puts("\nInsert 100 Elements");
    for(int i = 1; i <= 100; i++)                   //insert elemnts to queue
        enqueue(temp, lastElementIdx, length, i);
    
    puts("\nprintQueue #2:");                   //print queue
    printQueue(*temp,*lastElementIdx);
    
    puts("\nAusgabe von dequeue:");             // dequeue array
    while(*lastElementIdx > -1)
        printf("Element: %d\tQueue length: %d\n", dequeue(temp, lastElementIdx, length), *length);
}


void test2(int **arr, int* lastElementIdx, int *length)
{
    int **temp = arr;
    puts("\n************\nEnqueue beyond queue[N-1]:");
    puts("Queue aufbauen...");
    for(int i = 1; i <= 150; i++)
        enqueue(temp, lastElementIdx, length, i);
    
    puts("Queue:");
    printQueue(*temp,*lastElementIdx);
    
    puts("\nDequeue:");
    while(*lastElementIdx > -1)
        printf("Element: %d\tQueue length: %d\n", dequeue(temp, lastElementIdx, length),*length);
    
    
}