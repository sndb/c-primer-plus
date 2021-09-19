#include <ctype.h>
#include <stdio.h>

int main(void)
{
	char ch;
	int charcount = 0;
	int wordcount = 0;
	int inword = 0;

	while ((ch = getchar()) != EOF) {
		if (isspace(ch) || ispunct(ch)) {
			if (inword)
				wordcount++;
			inword = 0;
		} else {
			inword = 1;
			charcount++;
		}
	}
	if (wordcount)
		printf("Average number of letters per word: %g.\n", (double)charcount / wordcount);
	else
		printf("There are no words.\n");

	return 0;
}
