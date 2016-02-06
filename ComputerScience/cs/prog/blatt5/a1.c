#include <stdio.h>

int main()
{
	int n = 5;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++)
			printf("%d ", j);
		printf("\n");
	}
	
	for(int i = n; i > 0; n--, i--){
		for(int j = 1; j < n; j++)
			printf("%d ", j);
		printf("\n");
	}

	return 0;
}