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
