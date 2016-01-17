#ifndef ADDRESS_H
#define ADDRESS_H
#define MAXCHAR 30
#define SIZE 10
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct address {
    char vorname[MAXCHAR];
    char nachname[MAXCHAR];
    char addresse[MAXCHAR];
    short alter;
};

//used for typecasting compare function
typedef int (*compare_func)(const void*, const void*);

//compare function for qsort
int sort_vorname(struct address *, struct address *);

//2nd compare function for qsort
int sort_nachname(struct address *, struct address *);

//3rd compare function
int laenge_vorname(struct address *, struct address *);

// Liest einen Adressdatensatz vom Benutzer ein und gibt diesen in Form eines
// struct zurück
struct address input_address(void);

// Übernimmt einen Adressdatensatz in form eines struct und gibt diesen auf dem
// Bildschirm aus
void print_address(const struct address *addr);

//cleans buffer
void clean_buffer();

//gets operation as user input
void get_operation(int *);

//sorts array
void sort(int *);

#endif /*ADDRESS_H*/
