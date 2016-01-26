#include <stdlib.h>
#include <stdio.h>
#define DEBUG(msg) \
    fprintf(stderr, "%s%s%s%s%d%s%s\n", \
        __FILE__, ":", __func__, "():", __LINE__, " --> ", msg);

void test(void){
    DEBUG("Hilfe");
}

void foo(void);

int main(int argc, char**args){

    test();
    DEBUG("Hilfe");
    foo();

    return EXIT_SUCCESS;
}

void foo(void){
    //some code here
    //and here

    DEBUG("Dafaq is happening here?");
}

