#include <ctype.h>
#include <stdio.h>

char *read_first_word(char ar[])
{
	char c;
	int inword = 0;
	size_t i = 0;

	while ((c = getchar()) != EOF) {
		if (isspace(c)) {
			if (!inword)
				continue;
			else
				break;
		}
		inword = 1;
		ar[i] = c;
		i++;
	}
	ar[i] = '\0';

	return ar;
}

int main(void)
{
	char ar[20];

	read_first_word(ar);
	printf("%s\n", ar);

	return 0;
}
