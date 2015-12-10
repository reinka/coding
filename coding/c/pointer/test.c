#include <stdio.h>
#include <stdint.h>

int comparing_pointers(int* p, int* q)
{
	return (p > q);
}

int main()
{
	int num = 5, vector[] = {28,41,7}, *p0 = vector, *p1 = p0++, *p2 = p1++, *pi =&num;
	char letter = 'a', *pc = &letter;
	void *pv = &num;
	//pointer to function:
	//void (*foo)(void);

	printf("Value of pi before: %p\n", pi++);
	printf("Value of pc before: %p\n", pc++);
	printf("Value of pv before: %p\n", pv);
	pv = pv + 1;

	printf("Value of pi after: %p\n", pi);
	printf("Value of pc after: %p\n", pc);
	printf("Value of pv after: %p\n", pv);
	pi = (int*) pv;
	pv = &letter;

	printf("Value of pi: %d\n", comparing_pointers(p2,p0));
	printf("Value of pv: %d\n", comparing_pointers(p0,p1));

	//size_t size = sizeof(void*);
	printf("%ld\n", sizeof(char*));

	//printf("%d\n", *p); illegal, für p = Null;
	return 0;


}