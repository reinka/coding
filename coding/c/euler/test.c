#include <stdio.h>

int print_it(int n){
	while(n > 0)
		return n + print_it(n-1);
	return 0;
}

int main(){

	printf("%d\n", print_it(5));
	return 0;
}