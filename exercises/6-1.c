#include <stdio.h>

int main(void)
{
	const int LENGTH = 26;
	char letters[LENGTH];
	char ch;
	int i;

	for (ch = 'a', i = 0; i < LENGTH; ch++, i++)
	{
		letters[i] = ch;
	}

	for (i = 0; i < LENGTH; i++)
	{
		printf("%c", letters[i]);
	}
	printf("\n");

	return 0;
}
