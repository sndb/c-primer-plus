#include <ctype.h>
#include <stdio.h>

#define LEN 20

char *fetch_nchars(char ar[], size_t n)
{
	size_t i;
	char c;

	for (i = 0; i < n - 1; i++) {
		if ((c = getchar()) == EOF || isspace(c))
			break;
		ar[i] = c;
	}
	ar[i] = '\0';

	return ar;
}

int main(void)
{
	char ar[LEN];

	fetch_nchars(ar, LEN);
	printf("%s", ar);

	return 0;
}
