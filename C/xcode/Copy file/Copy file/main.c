/*
 ============================================================================
 Name        : copy_file.c
 Author      : Andrei Poehlmann
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define FILENAME "/Users/slackoverflow/coding/C/workspace/copy_file/src/datei.txt"
#define COPY "/Users/slackoverflow/coding/C/workspace/copy_file/src/kopie.txt"


int main(int argc, const char * argv[]) {
       
    FILE *fp = fopen(FILENAME, "r");
    FILE *fpcopy = fopen(COPY, "w");
    
    if(fp == NULL || fpcopy == NULL){
        printf("Error while opening file %s or %s", FILENAME, COPY);
        return EXIT_FAILURE;
    }
    for( int c; (c = fgetc(fp)) != EOF; ){
        if(fputc(c, fpcopy) == EOF){
            printf("Error while copying %s / %s",FILENAME, COPY);
            return EXIT_FAILURE;
        }
        
    }
    
    if(fclose(fp) != 0 || fclose(fpcopy) != 0){
        puts("Error while closing files.");
        return EXIT_FAILURE;
    }
    
    
    return EXIT_SUCCESS;
}
