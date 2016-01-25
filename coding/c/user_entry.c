typedef enum _user_entry { MORE_DATA = 1, QUIT = 2, INVALID = 3, PRINT = 4 } user_entry;

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