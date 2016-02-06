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
    
    user_entry data_type = get_data_type();
    if (data_type == DOUBLE) {
        arr = create_array(sizeof(double), SIZE);
    }
    else{
        arr = create_array(sizeof(int), SIZE);
    }
    
    while (1) {
    
    user_entry entry = get_operation();

        if (entry == QUIT) {
            break;
        }
    
        else if (entry == MORE_DATA) {
            if (i < SIZE) {
                if (data_type == DOUBLE) {
                    double value;
                    get_double_data(&value);
                    insert(&arr, i++, &value);

                }
                else {
                    int value;
                    get_int_data(&value);
                    insert(&arr, i++, &value);

                }
                
            }else
                puts("Datensatz voll");
            
            printf("\nSie haben noch genuegend Speicher fuer %d Daten.\n\n", SIZE - i);
        }
        
        else if (entry == PRINT){
            if(i == 0){
                puts("\n\nEs sind noch keine Datensaetze vorhanden. Geben Sie bitte erst welche ein.\n\n");
            } else{
                for (int j = 0; j < i;j++) {
                    arr.element_size == sizeof(double) ? printf("%f ",((double*) arr.data)[j]) : printf("%d ",((int*) arr.data)[j]) ;
                }puts("");
            }
        }
    
    
    
    
    
    
    }
        
        
        
    
    
    
    
    return 0;
}
