#include <stdio.h>

int is_within(char c, const char *s)
{
	while (*s != '\0') {
		if (*s == c)
			return 1;
		s++;
	}
	return 0;
}

int main(void)
{
	char *words[] = {"apple", "banana", "peach", "orange"};
	int find;
	char search_for = 'e';

	for (size_t i = 0; i < sizeof words / sizeof *words; i++) {
		find = is_within(search_for, words[i]);
		if (find)
			printf("Found '%c': %s\n", search_for, words[i]);
		else
			printf("Word '%s' has no character '%c'\n", words[i], search_for);
	}

	return 0;
}
