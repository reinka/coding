#include <stdio.h>

int main()
{
	int x = 0, y = 0, z = 0, n = 2, count = 0;

	for(x = 0; x < n; x++){
		for(y = x + 1; y <= n; y++){
			for( z = y + 1; z <=n; z++){
				printf("(%d, %d, %d)\n",x, y, z);
				count++;
			}	

		}
	}

	for(y = 0; y < n; y++){
		for(x = y + 1; x <= n; x++){
			for( z = x + 1; z <=n; z++){
				printf("(%d, %d, %d)\n",x, y, z);
				count++;
			}	
		}
	}

	for(x = 0; x < n; x++){
		for(z = x + 1; z <= n; z++){
			for( y = z + 1; y <=n; y++){
				printf("(%d, %d, %d)\n",x, y, z);
				count++;
			}	
		}
	}

	for(x = 0; x < n; x++){
		for(y = x + 1; y <= n; y++){
			for( z = y + 1; z <=n; z++){
				printf("(%d, %d, %d)\n",x, y, z);
				count++;
			}	
		}
	}

	for(z = 0; z < n; z++){
		for(y = z + 1; y <= n; y++){
			for( x = y + 1; x <=n; x++){
				printf("(%d, %d, %d)\n",x, y, x);
				count++;
			}	
		}
	}

	for(z = 0; z < n; z++){
		for(x = z + 1; x <= n; x++){
			for( y = x + 1; y <=n; y++){
				printf("(%d, %d, %d)\n",x, y, z);
				count++;
			}	
		}
	}

	printf("%d\n", count);

	return 0;
}