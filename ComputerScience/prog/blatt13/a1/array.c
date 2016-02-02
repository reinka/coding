cd//
//  array.c
//  C
//
//  Created by Andrei Poehlmann on 29/01/16.
//  Copyright © 2016 Andrei Poehlmann. All rights reserved.
//

#include "array.h"





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


