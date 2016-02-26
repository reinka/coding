#include<stdio.h>

void decompose(double x, long *int_part, double *frac_part);

int main(void)
{
    double d;
    long i;

    decompose(3.14159, &i, &d);

    printf("i = %ld\nd = %f\n", i, d);

    return 0;
}

void decompose(double x, long *int_part, double *frac_part)
{
    *int_part = (long) x;
    *frac_part = x - *int_part;
}

/*
//TEST OHNE POINTER -> value von i, d in main unverändert

void decompose(double x, long i, double d);

int main(void)
{
    double d;
    long i;

    decompose(3.14159, i, d);

    printf("%ld\n%f\n", i, d);

    return 0;
}

void decompose(double x, long i, double d)
{
    i = (long) x;
    d = x - i;

    printf("Function output: i = %ld, d = %f\n", i, d);
}
*/