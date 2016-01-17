#ifndef ADDRESS_H
#define ADDRESS_H
#define MAXCHAR 50
#define SIZE 3
#include <stdio.h>
#include <stdlib.h>

struct address {
    char vorname[MAXCHAR];
    char nachname[MAXCHAR];
    char addresse[MAXCHAR];
    short alter;
};

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

#endif /*ADDRESS_H*/
