/*
 *Asks user for double input, and checks for right input.
 *scanf-loop will not end until double data has been inserted.
 */
void get_double_data(double *value) {
    puts("Enter Double:");
    char ch;
    while(scanf("%lf%c", value, &ch) != 2 || ch != '\n'){
        puts("Wrong input, Double only, please:");
        clean_buffer();
    }
}
