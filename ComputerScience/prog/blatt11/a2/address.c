#include "address.h"

// Liest einen Adressdatensatz vom Benutzer ein und gibt diesen in Form eines
// struct zurück
struct address input_address(void) {
    struct address data;
    printf("Vorname : ");
    fgets(data.vorname, MAXCHAR, stdin);
    printf("Nachname : ");
    fgets(data.nachname, MAXCHAR, stdin);
    printf("Adresse : ");
    fgets(data.addresse, MAXCHAR, stdin);
    printf("Alter : ");
    do {
        scanf("%hd", &data.alter);
    } while (getchar() != '\n');
    
    return data;
}

// Übernimmt einen Adressdatensatz in form eines struct und gibt diesen auf dem
// Bildschirm aus
void print_address(const struct address *addr) {
    printf("\n\n");
    printf("Vorname : %s", addr->vorname);
    printf("Nachname : %s", addr->nachname);
    printf("Addresse : %s", addr->addresse);
    printf("Jahr : %hd\n\n", addr->alter);
}

//cleans buffer
void clean_buffer(void){
    char ch;
    while((ch = getchar()) != '\n' && ch != EOF)
        ;
}

//gets operation as user input
void get_operation(int* operation) {
    
    puts("Willkommen im Menue. Waehlen Sie eine Option aus.");
    puts("0 = neuen Datensatz hinzufuegen\t1 = Datensaetze ausgeben\t2 = Programm beenden");
    
    
    while(scanf(" %d", operation) != 1 || (*operation < 0 || *operation > 2)) {
        puts("Wrong input. Bitte geben Sie eine gueltige Ziffer (0-2) ein");
        clean_buffer();
    } clean_buffer();
    
}

int sort_vorname(struct address *a, struct address *b) {
    
    
    char *first = a->vorname;
    char *second = b->vorname;

    
    int len = strlen(first); //implict conversion to int, since int should suffice
    
    for (int i = 0; i <= len; i++) {
        
        /**
         *compare chars with each other. use toupper to ignore upper or lower letter spelling
         */
        int result = toupper(*(first + i)) - toupper(*(second + i));
        
        if(result > 0) {
            return 1;
        }
        else if (result < 0){
            return -1;
        }
    }
    
    /**
     *if the loop terminated without hitting return:
     *a) either a & b are equal or
     *b) a consists of the same chars as b, but has less chars than b
     *this has to be checked now
     */
    if (strlen(first) < strlen(second)) {
        return 1;
    }
    else {
        return 0;
    }
}


int sort_nachname(struct address *a, struct address *b) {

    
    
    char *first = a->nachname;
    char *second = b->nachname;
    
    
    int len = strlen(first); //implict conversion to int, since int should suffice
    
    for (int i = 0; i <= len; i++) {
        
        /**
         *compare chars with each other. use toupper to ignore upper or lower letter spelling
         */
        int result = toupper(*(first + i)) - toupper(*(second + i));
        
        if(result > 0) {
            return -1;
        }
        else if (result < 0){
            return 1;
        }
    }
    
    /**
     *if the loop terminated without hitting return:
     *a) either a & b are equal or
     *b) a consists of the same chars as b, but has less chars than b
     *this has to be checked now
     */
    if (strlen(first) < strlen(second)) {
        return -1;
    }
    else {
        return 0;
    }
    
}

int laenge_vorname(struct address *a, struct address *b) {
    
    char *first = a->vorname;
    char *second = b->vorname;
    
    short lenA = strlen(first);
    short lenB = strlen(second);
    
    if(lenA > lenB){
        return 1;
    }
    else if (lenA < lenB){
        return -1;
    }
    else{ //auch hier Fallunterscheidung
        if (strlen(a->nachname) > strlen(b->nachname)) {
            return 1;
        }
        else if (strlen(a -> nachname) < strlen(b -> nachname)){
            return -1;
        }
        else
            return 0;
    }
}
