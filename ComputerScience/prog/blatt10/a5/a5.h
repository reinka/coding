#ifndef A5_H
#define A5_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#endif

int compar_value(void* thunkIn, const void *x, const void *y);
int int_to_bin(int x);
int compar_binary_ones(void* thunkIn, const void *x, const void *y);
int compar_longest_sequence_of_equal_bits(void* thunkIn, const void* x, const void* y); 
void print_array(int *arr, size_t n);
void print_sort_options(void);
void get_operation(int *operation);
void get_number_of_elements(long unsigned *numberOfElements);
void get_array(int *arr, long unsigned *numberOfElements);
void get_order(int *thunk);