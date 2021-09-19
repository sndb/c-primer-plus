#include <stdio.h>
#include <string.h>

int main(void)
{
	const int S_LEN = 256;
	char s[S_LEN];
	int i;

	for (i = 0; scanf("%c", &s[i]), s[i] != '\n'; i++)
		;

	for (i = strlen(s); i >= 0; i--)
	{
		printf("%c", s[i]);
	}
	printf("\n");

	return 0;
}
