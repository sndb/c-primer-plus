#include <stdio.h>
#include <string.h>

int main(void)
{
	char s[64];
	int i;

	printf("Enter a word to be reversed: ");
	scanf("%s", s);
	for (i = strlen(s); i >= 0; i--)
	{
		printf("%c", s[i]);
	}
	printf("\n");

	return 0;
}
