//Blatt 3, Aufgabe 4

#include <stdio.h>

int main(void)
{
    int n = 1024, i = 4; 
    
    //Startwert = 4, da die erste 4. Zahl von 1 bis n 4 ist
    while(i <= n){
        printf("%d\n", i);
        i += 4;
    }
    
    return 0;
}
