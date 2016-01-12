//
//  main.c
//  whateva
//
//  Created by Andrei Poehlmann on 04/01/16.
//  Copyright © 2016 Andrei Poehlmann. All rights reserved.
//

/*Deklarieren Sie ein Array queue von ganzen Zahlen mit 100 Elementen. Implementieren
 Sie mit diesem Array eine Queue1. Dazu müssen Sie folgende Funktionen
 implementieren:*/
#include "a3.h"

int main(int argc, char const *argv[])
{
    int startingPoint = -1, *lastElementIdx = &startingPoint, N = 100, *length = &N;
    int *queue = (int*) calloc(*length, sizeof(*queue));
    
    
    test1(&queue, lastElementIdx, length);
    test2(&queue, lastElementIdx, length);
    
    free(queue);
    
    return 0;
}

