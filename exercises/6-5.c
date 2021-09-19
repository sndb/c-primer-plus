#include <stdio.h>

int main(void)
{
	int rows;
	int delta;
	int spaces;
	int i;
	int r;
	char ch;

	printf("Enter an uppercase letter: ");
	scanf("%c", &ch);
	delta = ch - 'A';

	for (rows = 0; rows <= delta; rows++)
	{
		for (spaces = 0; spaces < delta - rows; spaces++)
		{
			printf(" ");
		}
		for (i = 0; i <= rows; i++)
		{
			printf("%c", 'A' + i);
		}
		for (r = 1; r <= rows; r++)
		{
			printf("%c", ch - delta + rows - r);
		}
		printf("\n");
	}

	return 0;
}
