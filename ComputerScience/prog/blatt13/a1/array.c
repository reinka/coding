//
//  array.c
//  C
//
//  Created by Andrei Poehlmann on 29/01/16.
//  Copyright © 2016 Andrei Poehlmann. All rights reserved.
//

#include "array.h"




//inserts element
void insert(array_t *arr, size_t offset, void *value){
    memcpy( ((char*)(arr->data)) + (offset * arr->element_size), value, arr->element_size);
}

// returns a new array which can store <length> elements of any
// type that can be stored in <element_size> bytes  <length> elements
array_t create_array(size_t element_size, unsigned long long length){
    array_t arr;
    arr.length = length;
    arr.element_size = element_size;
    arr.data = malloc(element_size * length);
    return arr;
}

// initializes all bytes of the array to zero
void init_array(array_t array) {
    memset(array.data, 0, array.length*array.element_size);
}

// clears any memory that is
void destroy_array(array_t array){
    if (array.data != NULL) {
        free(array.data);
        array.data = NULL;
    }
}

// sets element number <element_number> to the value given by the pointer
// <new_value>
void set_element(array_t array, unsigned long long element_number,
                 void *new_value);

// returns a pointer to element number <element_number>
void *get_element(array_t array, unsigned long long element_number);

void clean_buffer(void){
    
    while((getchar()) != '\n')
        ;
}

user_entry get_operation(void) {
    
    puts("Willkommen im Menue. Waehlen Sie eine Option aus.");
    puts("1 = neues Element hinzufuegen\t4 = Datensatz ausgeben\tq = Programm beenden");
    
    int operation;
    //char term;
    // try to parse integer
    int matched = scanf("%d", &operation);
    // if matched equals 1, matching was probably successful.
    if (matched == 1) {
        // if the next character is not a newline, the number was invalid
        // this means that there are characters remaining in the buffer
        if (getchar() != '\n') {
            clean_buffer();
            return INVALID;
        }else if (operation == 1){
            return MORE_DATA;
        }
        else if(operation == 4){
            return PRINT;
        } else {
            return INVALID;
        }
    }


    // now that's a bit tricky, because simply putting getchar() == 'q'
    // could remove a '\n' from the buffer. In this case, clearing the
    // the buffer will not work properly, because there is no '\n' until
    // the user enters the next line. So you might lose some input.
    char c = getchar();
    if (c == 'q' && getchar() == '\n') {
        return QUIT;
    }
    // if there is something remaining in the buffer, it is now the time
    // to clear it. This way, we assure that from now on any valid input
    // will be accepted, and not rejected because of remainig parts in the
    // buffer.
    if (c != '\n') {
        clean_buffer();
    }
    return INVALID;
    
}

void get_int_data(int *value) {
    puts("Enter Integer:");
    char ch;
    while(scanf("%d%c", value, &ch) != 2 || ch != '\n'){
        puts("Wrong input, Integer only, please:");
        clean_buffer();
    }
}

void get_double_data(double *value) {
    puts("Enter Double:");
    char ch;
    while(scanf("%lf%c", value, &ch) != 2 || ch != '\n'){
        puts("Wrong input, Double only, please:");
        clean_buffer();
    }
}

user_entry get_data_type(void){
    puts("Willkommen. Waehlen Sie einen Datentypen aus:");
    puts("d = Double\ni = Integer");
    char operation;
    user_entry result;
    while (1) {
        operation = getchar();
        
        if ((operation == 'd' && getchar() == '\n') || (operation == 'i' && getchar() == '\n')) {
            result = operation == 'd' ? DOUBLE : INT;
            return result;
        }
        else{
            puts("Wrong input, enter 'd' or 'i' only:");
            clean_buffer();
        }
    }
}
