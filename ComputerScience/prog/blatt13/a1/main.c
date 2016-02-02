//
//  main.c
//  C
//
//  Created by Andrei Poehlmann on 15/01/16.
//  Copyright © 2016 Andrei Poehlmann. All rights reserved.

#include "array.h"

//typedef enum _user_entry { MORE_DATA = 1, QUIT = 2, INVALID = 3, PRINT = 4, DOUBLE = 9, INT = 99 } user_entry;

int main(void) {
    
    array_t arr;
    int i = 0, SIZE = 15;
    
    
    while (1) {
    
    user_entry entry = get_operation();

        if (entry == QUIT) {
            break;
        }
    
        else if (entry == MORE_DATA) {
            if (i < SIZE) {
                
                
            }else
                puts("Datensatz voll");
            
            printf("\nSie haben noch genuegend Speicher fuer %d Daten.\n\n", SIZE - i);
        }
        
        else if (entry == PRINT){
            if(i == 0){
                puts("\n\nEs sind noch keine Datensaetze vorhanden. Geben Sie bitte erst welche ein.\n\n");
            } else{
                for (int j = 0; j < i;j++) {

                }puts("");
            }
        }
    
    
    
    
    
    
    }
        
        
        
    
    
    
    
    return 0;
}
