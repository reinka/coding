//
//  main.c
//  C
//
//  Created by Andrei Poehlmann on 15/01/16.
//  Copyright © 2016 Andrei Poehlmann. All rights reserved.

#include <stdio.h>
#include <stdlib.h>
#define MAXCHAR 30
#define SIZE 3

typedef enum _user_entry { MORE_DATA = 1, QUIT = 2, INVALID = 3, PRINT = 4 } user_entry;


struct dataEu {
    char name[MAXCHAR];
    int length;
    int quantity;
};

struct dataUs{
    char name[MAXCHAR];
    double length;
    int quantity;
};

// Liest einen Adressdatensatz vom Benutzer ein und gibt diesen in Form eines
// struct zurück
struct dataEu input_address(void);
struct dataUs input_address_us(void);
user_entry get_operation(void);
void print_address(const struct dataEu *data);
void print_address_us(const struct dataUs *data);
void clean_buffer(void);



int main(int argc, const char * argv[]) {
    
    int i = 0;
    
#ifdef INCH
    struct dataUs date[SIZE];
#else
    struct dataEu data[SIZE];
#endif
    
    while (1) {
        
        user_entry entry = get_operation();
        
        if (entry == QUIT) {
            break;
        }
        
        
        else if (entry == MORE_DATA){
            if (i < SIZE){
                #ifdef INCH
                    date[i++] = input_address_us();
                #else
                    data[i++] = input_address();
                #endif
            }
            else
                puts("\n\nDatensatz voll. Keine Aufnahme zusaetzlicher Daten moeglich.\n\n");
        }

        else if (entry == PRINT){
            if(i == 0){
                puts("\n\nEs sind noch keine Datensaetze vorhanden. Geben Sie bitte erst welche ein.\n\n");
            }
                #ifdef INCH
                for (int j = 0; j < i ; j++) {
                    print_address_us(&date[j]);
                }
            
                #else
                for (int j = 0; j < i; j++) {
                    print_address(&data[j]);
                }
                #endif
        }
    }
    
    return EXIT_SUCCESS;
}



//cleans buffer
void clean_buffer(void){
    char ch;
    while((ch = getchar()) != '\n')
        ;
}

//gets operation from user
user_entry get_operation(void) {
    
    puts("Willkommen im Menue. Waehlen Sie eine Option aus.");
    puts("1 = neuen Datensatz hinzufuegen\t4 = Datensaetze ausgeben\tq = Programm beenden");
    
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
        } else if (operation == 1){
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

struct dataEu input_address(void) {
    struct dataEu data;
    char ch;
    
    printf("Name : ");
    fgets(data.name, MAXCHAR, stdin);
    
    printf("Length : ");
    while(scanf(" %d%c", &data.length, &ch) != 2 || ch != '\n'){
        // if the next character is not a newline, the number was invalid
        // this means that there are characters remaining in the buffer
        clean_buffer();
        puts("Wrong input. Integer only, please. Try again.");
    }
    
    printf("Quantity : ");
    while(scanf(" %d%c", &data.quantity,&ch) != 2 || ch != '\n'){
        // if the next character is not a newline, the number was invalid
        // this means that there are characters remaining in the buffer
        clean_buffer();
        puts("Wrong input. Integer only, please. Try again.");
    }
    
    return data;
}


struct dataUs input_address_us(void) {
    struct dataUs date;
    char ch;
    
    printf("Name : ");
    fgets(date.name, MAXCHAR, stdin);
    
    printf("Length : ");
    while(scanf(" %lf%c", &date.length, &ch) != 2 || ch != '\n'){
        // if the next character is not a newline, the number was invalid
        // this means that there are characters remaining in the buffer
        clean_buffer();
        puts("Wrong input. Double only, please. Try again.");
    }
    
    printf("Quantity : ");
    while(scanf(" %d%c", &date.quantity, &ch) != 2 || ch != '\n'){
        // if the next character is not a newline, the number was invalid
        // this means that there are characters remaining in the buffer
        clean_buffer();
        puts("Wrong input. Integer only, please. Try again.");
    }
    
    return date;
}

void print_address(const struct dataEu *data) {
    printf("\n\n");
    printf("Name : %s", data->name);
    printf("Length : %d\n", data->length);
    printf("Quantity : %d\n", data->quantity);
}

void print_address_us(const struct dataUs *data) {
    printf("\n\n");
    printf("Name : %s", data->name);
    printf("Length : %lf\n", data->length);
    printf("Quantity : %d\n", data->quantity);
}

