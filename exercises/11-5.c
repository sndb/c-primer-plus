#include <stdio.h>

char *search_char(const char *s, char c)
{
	while (*s != '\0') {
		if (*s == c)
			return (char *)s;
		s++;
	}
	return NULL;
}

int main(void)
{
	char *words[] = {"apple", "banana", "peach", "orange"};
	char *find;
	char search_for = 'e';

	for (size_t i = 0; i < sizeof words / sizeof *words; i++) {
		find = search_char(words[i], search_for);
		if (find)
			printf("Word '%s' has character '%c' at %td position\n", words[i],
			       search_for, find - words[i] + 1);
		else
			printf("Word '%s' has no character '%c'\n", words[i], search_for);
	}

	return 0;
}
