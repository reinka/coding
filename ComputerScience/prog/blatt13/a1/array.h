#ifndef VERSATILE_ARRAY
#define VERSATILE_ARRAY

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef enum _user_entry { MORE_DATA = 1, QUIT = 2, INVALID = 3, PRINT = 4, DOUBLE = 9, INT = 99 } user_entry;

typedef struct {
  unsigned long long length;
  size_t element_size;
  void *data;
} array_t;

//inserts element into array
//void insert(array_t *arr, size_t offset, void *value);


// returns a new array which can store <length> elements of any
// type that can be stored in <element_size> bytes  <length> elements
array_t create_array(size_t element_size, unsigned long long length);

// initializes all bytes of the array to zero
void init_array(array_t array);

// clears any memory that is
void destroy_array(array_t array);

// sets element number <element_number> to the value given by the pointer
// <new_value>
void set_element(array_t array, unsigned long long element_number,
                 void *new_value);

// returns a pointer to element number <element_number>
void *get_element(array_t *array, unsigned long long element_number);

//cleans buffer
void clean_buffer(void);


//gets operation from user
user_entry get_operation(void);

//gets integer data input
void get_int_data(int *value);

//gets double data input
void get_double_data(double *value);

//gets data type of input
user_entry get_data_type(void);



#endif
