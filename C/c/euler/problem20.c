#include <stdio.h>
#include <time.h>

long double factorial(int n){
	long double result = 1;
	while(n > 1){
		result *= n--;
		printf("%Lf\n", result); 
	}
	return result;
}

unsigned long long digit_count(long double fac){
	unsigned long long digit_count[45], i = 0;
	unsigned long long divisor = 10000000000000;
	while(fac > 0){
		fac /= divisor;
		if(fac)
		digit_count[i++] = fac;
	}
	return *digit_count;
}

long long frac_to_long(long double fac)
{
	
}

int main(int argc, char const *argv[])
{
	int n = 35;
	clock_t begin,end;

	begin = clock();
	while(n > 1){
		printf("Sum of digits: %lld\n\n", digit_count(factorial(n)));
		n-=1;
	}
	end = clock();

	printf("Duration: %f\n", (double) (end - begin) / CLOCKS_PER_SEC);

	return 0;
}