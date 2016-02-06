#include <stdio.h>

int main()
{
	int x = 0, y = 0, z = 0, n = 2, count = 0;

	for(x = 0; x <= n; x++){
		for(y = 0; y <= n; y++){
			if(y == x || y > n)
				continue;
			for( z = 0; z <= n; z++){
				if(z == y || z == x || z > n)
					continue;
				printf("(%d, %d, %d)\n",x, y, z);
				count++;
			}
		}
	}

	printf("%d Permutationen.\n", count);

	return 0;
}