#include <stdio.h>

int main(int argc, char const *argv[])
{
	char *titles[] = {"a book title here", "another title", "a third title",
			"a fourth title", "a fifth title here",
			"a sixth sense and the like", "an here goes more",
			" and even more"}, **bestBooks[3], **englishBooks[4];

	int num = 5;
	int *const p=&num;
	printf("%p\n", p);
	printf("%d\n", *p++);
	printf("%p\n", p);

	bestBooks[0] = &titles[0];
	bestBooks[1] = &titles[3];
	bestBooks[2] = &titles[5];
	
	//alternativ durch derefenerzierung und pointer arithmetik:
	*englishBooks = titles;
	*(englishBooks + 1) = titles + 4;
	*(englishBooks + 2) = titles + 6;
	*(englishBooks + 3) = titles + 2;

	printf("%s\n", *(*bestBooks));
	printf("%s\n", *(*(bestBooks+1)));
	printf("%s\n", *(*(bestBooks+2)));

	printf("%s\n", *(*(englishBooks)));
	printf("%s\n", *(*(englishBooks+1)));
	printf("%s\n", *(*(englishBooks+2)));
	printf("%s\n", *(*(englishBooks+3)));

	return 0;
}