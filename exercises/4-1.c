#include <stdio.h>

int main(void)
{
	char first[25];
	char last[50];

	printf("Enter your name.\n");
	scanf("%s %s", first, last);
	printf("Your name is %s %s.\n", last, first);

	return 0;
}
