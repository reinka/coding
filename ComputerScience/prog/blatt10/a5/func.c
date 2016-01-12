#include "a5.h"

/**
 *Function to compare two values of an array
 */
int compar_value(void* thunkIn, const void *x, const void *y)
{
    //int *p = (int*) x, *q = (int*) y;
    
    
    
    return (*(int*) thunkIn) ? (-1 * (*(int*)x - *(int*)y)) : (*(int*)x - *(int*)y);
}


/**
 *function converting decimal integer to binary representation
 */
int int_to_bin(int x) {
    return (x == 0 || x == 1 ? x : ((x % 2) + 10 * int_to_bin(x / 2)));
}


/**
 *function comparing occurring ones between two binary numbers
 */
int compar_binary_ones(void* thunkIn, const void *x, const void *y)
{
    
    int *p = (int*)x, *q = (int*)y, *thunk = (int*) thunkIn;
    int count = 0, arr[2];                
                 //^^
                 //array for holding the binary representations
    
    arr[0] = int_to_bin(*p);
    arr[1] = int_to_bin(*q);
    
    //printf("%08d\n%08d\n",arr[0],arr[1]);
    
    for (int i = 0; i < 2; i++) {
        while (arr[i]) {
            
            if (arr[i]%10) {
                
                /*
                 *substract numb. of occuring 1s of 2nd binary dig. from the 1st one
                 */
                
                i ? count-- : count++;
                
            }
            
            arr[i] /= 10;
        } //printf("%d\n",count);
    }
    
    if (count == 0) {
        return 0;
    }
    
    count = count < 0 ? -1 : 1;
    
    return *thunk ? (-1 * count) : count;
}


/**
 *comparing numbers regarding longest sequence of equal bits
 */
int compar_longest_sequence_of_equal_bits(void* thunkIn, const void* x, const void* y) {
    
    int *p = (int *) x, *q = (int *) y;
    int *thunk = (int*) thunkIn;
    int n, count, pointOfReference, arr[2], maxSequence[2];
                                            //^^
                                            //array for holding value of max occurring sequence
    arr[0] = int_to_bin(*p);
    arr[1] = int_to_bin(*q);
    
    for (int i = 0; i < 2; i++) {
        maxSequence[i] = 0;
        int numberOfDigits = 0;
        n = arr[i];
        count = 0;
        
        /* *
         *1. set pointOfReference equal to the first bit of max sequence
         *2. while there is bits in number: start counting the continual occurences
         *3. if continuation is interrupted:
         *3.1               counter <- 1
         *3.2               if maxSequence[i] < counter: maxSequence[i] <- counter
         *3.3               pointOfReference <- n % 10;
         *4. else:
         *4.1     if maxSequence < counter: maxSequence <- counter
         *4.2     else maxSequence = maxSequence
         *5. go to step 2
         */
        
        pointOfReference = arr[i] % 10;
        
        while (n) {
            
            count++;
            numberOfDigits++; //keep track of how many digits there are
            int bit = n % 10;
            
            if (bit != pointOfReference){   //step 3
                count = 1;
                
                maxSequence[i] = maxSequence[i] < count ? count : maxSequence[i];
                
                pointOfReference = bit;
            }
            else{
                maxSequence[i] = maxSequence[i] < count ? count : maxSequence[i];
            }
            
            n /= 10;
            
        } //printf("%d\n",count);
        
        
        
        /**
         *(I assume?) We are supposed to work with 8 bit numbers, but the int_to_bin function stops as soon as
         *the calculation to binary is completed, which means there can be cases where the binary
         *number consists of less than 8 digits. In this case, we would miss additional 0s which could
         *increase the max sequence if the last pointOfReference is 0. Example: 13 is 0000 1101 in binary.
         *The result of int_to_bin would be only 1101 though. So the maxSequence up until now would be 2 for
         *the last two 1 digits in the sequence. When in fact maxSequence should be 4, for the additional four 0000 of the
         *8 bit representation. So we have to adjust this here. Beware, there are different cases to consider, depending
         *on which position the last digit occured and whether it was 0 or 1:
         */
        
        if (numberOfDigits < 8) {
            
            
            int rest = 8 - numberOfDigits; //0s that are left over
            
            /*
             *if last digit was 1, residue = rest, else (0) residue = maxSequence[i] + rest
             */
            
            int residue = pointOfReference ? rest : (count + rest);
            
            /*update maxSequence in case it is smaller than residue*/
            
            maxSequence[i] = maxSequence[i] < residue ? residue : maxSequence[i];
            
            
        } //printf("\n Count = %d\nNumber: %d\nMaxSequence[%d] =  %d\n", count, arr[i], i, maxSequence[i]);
        
        
    }
    
    int result = 0;
    
    if (maxSequence[0] != maxSequence[1]) {
        result = maxSequence[0] < maxSequence[1] ? -1 : 1;
    } //printf("MaxSequence[%d] = %d\tMaxSequence[%d] = %d\n", 0, maxSequence[0], 1, maxSequence[1]);
    
    //printf("%d\n", *thunk);
    return *thunk ? (result * -1) : result ;
    
}

/**
 *prints array
 */
void print_array(int *arr, size_t n) {
    for (int i = 0; i < n; i++)
        printf("%d\t", arr[i]);
    puts("");
}

/**
 *prints sorting options
 */
void print_sort_options(void){
    puts("How would you like to sort it?");
    puts("0 = sort by value");
    puts("1 = sort by occurences of 1s regarding the numbers' binary representation");
    puts("2 = sort by longest sequence of equal bits regarding the numbers' binary representation");
}

/**
 *gets sorting operation from the user
 */
void get_operation(int *operation){
    
    while (scanf(" %d", operation) != 1){
        puts("Wrong input, please enter one of the given inputs above");
        while (getchar() != '\n') {
            ;
        }
    }while (getchar() != '\n');
}

/**
 *gets numer of elements for the variable length array of the user
 */
void get_number_of_elements(long unsigned *numberOfElements) {
    
    puts("How many Elements would you like to enter");
    while (scanf(" %lu", numberOfElements) != 1){
        puts("Wrong input, please enter an integer");
        while (getchar() != '\n') {
            ;
        }
    }while (getchar() != '\n');
}

/**
 *gets variable length array from the user
 */
void get_array(int *arr, long unsigned *numberOfElements){
    
    puts("Enter your elements");
    
    for(int i = 0; i < *numberOfElements; i++) {
        int elements;
        while (scanf(" %d", &elements) != 1){
            puts("Wrong input, please enter an integer");
            while (getchar() != '\n') {
                ;
            }
        }while (getchar() != '\n');
        
        arr[i] = elements;
    }
    
}

/**
 *gets sorting order from the user
 */
void get_order(int *thunk){
    
    puts("Would you like to sort it in ascending or descending order?");
    puts("0 = ascending");
    puts("1 = descending");
    
ascending:
    while (scanf(" %d", thunk) != 1){
        puts("Wrong input, please enter one of the given inputs above");
        while (getchar() != '\n') {
            ;
        }
    }while (getchar() != '\n');
    
    if ( (*thunk != 0) && (*thunk != 1)) {
        puts("Wrong input, please enter one of the given inputs above");
        goto ascending;
    }
    puts("Great, here we go:");
    puts("Sorting...");
}