void get_int_data(int *value) {
    puts("Enter Integer:");
    char ch;
    while(scanf("%d%c", value, &ch) != 2 || ch != '\n'){
        puts("Wrong input, Integer only, please:");
        clean_buffer();
    }
}
