#include <stdio.h>

#define SIZE 6

int starts_with(const char *str, const char *substr)
{
	while (*str == *substr) {
		str++;
		substr++;
		if (!*substr)
			return 1;
	}
	return 0;
}

char *string_in(const char *str, const char *substr)
{
	while (*str) {
		if (starts_with(str, substr))
			return (char *)str;
		str++;
	}
	return NULL;
}

int main(void)
{
	char *words[SIZE] = {"apple", "banana", "peach", "orange", "an", "n"};
	char *search_for = "an";
	char *match;

	for (size_t i = 0; i < SIZE; i++) {
		match = string_in(words[i], search_for);
		if (match)
			printf("'%s' is in '%s' at %td\n", search_for, words[i],
			       match - words[i] + 1);
		else
			printf("'%s' is not in '%s'\n", search_for, words[i]);
	}
	if (string_in("an", "anan"))
		printf("'anan' is in 'an'\n");
	else
		printf("'anan' is not in 'an'\n");

	return 0;
}
