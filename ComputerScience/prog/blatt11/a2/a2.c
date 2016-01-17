//
//  main.c
//  C
//
//  Created by Andrei Poehlmann on 15/01/16.
//  Copyright © 2016 Andrei Poehlmann. All rights reserved.

#include "address.h"

int main(int argc, const char * argv[]) {
    
    struct address data[SIZE];
    int i = 0, operation;
    
    while (1) {
        
        get_operation(&operation);
        
        if (operation == 2) {
            break;
        }
        else if (operation == 0){
            if (i < SIZE){
                data[i++] = input_address();
            }
            else
                puts("\n\nDatensatz voll. Keine Aufnahme zusaetzlicher Daten moeglich.\n\n");
        }
        else if (operation == 1){
            if(i == 0){
                puts("\n\nEs sind noch keine Datensaetze vorhanden. Geben Sie bitte erst welche ein.\n\n");
            }
            else{
                for (int j = 0; j < i ; j++) {
                    print_address(&data[j]);
                }
            }
        }
        
    }
    
    puts("Before qsort");
    for (int j = 0; j < i ; j++) 
        print_address(&data[j]);
    
    qsort((void *) &data, i, sizeof(struct address), (compare_func)sort_vorname);
    
    puts("After qsort vorname:");
    for (int j = 0; j < i ; j++)
        print_address(&data[j]);
    
    qsort((void *) &data, i, sizeof(struct address), (compare_func)sort_nachname);
    
    puts("After qsort nachname:");
    for (int j = 0; j < i ; j++)
        print_address(&data[j]);
    
    qsort((void *) &data, i, sizeof(struct address), (compare_func)laenge_vorname);
    
    puts("After qsort vorname laenge:");
    for (int j = 0; j < i ; j++)
        print_address(&data[j]);

            
            
    return EXIT_SUCCESS;
}
