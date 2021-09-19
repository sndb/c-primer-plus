#include <ctype.h>
#include <stdio.h>

int main(void)
{
	char c;
	int inword = 0;
	unsigned int word_count = 0;
	unsigned int ucase_count = 0;
	unsigned int lcase_count = 0;
	unsigned int punct_count = 0;
	unsigned int digit_count = 0;

	while ((c = getchar()) != EOF) {
		if (!isspace(c)) {
			if (!inword)
				word_count++;
			inword = 1;
		} else
			inword = 0;

		if (islower(c))
			lcase_count++;
		else if (isupper(c))
			ucase_count++;
		else if (ispunct(c))
			punct_count++;
		else if (isdigit(c))
			digit_count++;
	}
	printf("Report:\n"
	       "Number of words: %u\n"
	       "Number of uppercase letters: %u\n"
	       "Number of lowercase letters: %u\n"
	       "Number of punctuation characters: %u\n"
	       "Number of digits: %u\n",
	       word_count, ucase_count, lcase_count, punct_count, digit_count);

	return 0;
}
