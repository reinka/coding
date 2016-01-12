//
//  a5.c
//
//
//  Created by Andrei Poehlmann on 04/01/16.
//
//THIS PROGRAM IS WRITTEN TO WORK FOR 8 BIT NUMBERS ONLY SINCE IT WASN'T FURTHER SPECIFIED
//
//THUNK CAN BE USED TO INVERT THE OUTPUT (DESCENDING/ASCENDING ORDER)
#include "a5.h"

int main (int argc, char * argv[])
{
    
    /*
     * thunk = 0 -> ascending order
     * thunk = 1 -> descending order
     */
    
    int arr[] = {37, 57, 7, 13, 46}, thunk = 0, operation;
    size_t element_size = sizeof(arr[0]), numberOfElements = 5;
    int (*func_ptr[3])(void*, const void*, const void*) = {compar_value, compar_binary_ones, compar_longest_sequence_of_equal_bits};
    
    puts("Hello, you have the following array:");
    print_array(arr, numberOfElements);
    
    print_sort_options();
    puts("9 = enter your own array elements");
    
    
wrongInput:
    
    get_operation(&operation);
    
    if ( (operation != 0) && (operation != 1) && (operation != 2) && operation != 9) {
        puts("Wrong input, please enter one of the given inputs above");
        goto wrongInput;
    }
    
    
    
    if (operation == 9){
        
        get_number_of_elements(&numberOfElements);
        int arr[numberOfElements];
        
        get_array(arr, &numberOfElements);
        
        puts("Well done, here is your array");
        print_array(arr, numberOfElements);
        
        print_sort_options();
        
    wrongInput2:
        
        get_operation(&operation);
        
        if ( (operation != 0) && (operation != 1) && (operation != 2)) {
            puts("Wrong input, please enter one of the given inputs above");
            goto wrongInput2;
        }
        
        
        get_order(&thunk);
        
        qsort_r(arr, numberOfElements, element_size, &thunk, func_ptr[operation]);
        
        print_array(arr, numberOfElements);
        
    }
    
    else{
        
        get_order(&thunk);
        
        qsort_r(arr, numberOfElements, element_size, &thunk, func_ptr[operation]);
        
        print_array(arr, numberOfElements);
    }
    
    
    
    return EXIT_SUCCESS;
}