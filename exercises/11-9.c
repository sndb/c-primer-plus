#include <stdio.h>

#define ARSIZE 6
#define WORDSIZE 10

void reverse_string(char *s)
{
	char buf;
	char *b = s;

	while (*b)
		b++;
	while (s < b) {
		b--;
		buf = *s;
		*s = *b;
		*b = buf;
		s++;
	}
}

void show_array(char ar[][WORDSIZE], size_t n)
{
	for (size_t i = 0; i < n; i++)
		printf("%s ", ar[i]);
	putchar('\n');
}

int main(void)
{
	char words[ARSIZE][WORDSIZE] = {"apple", "banana", "peach", "orange", "ab", "c"};

	show_array(words, ARSIZE);
	for (size_t i = 0; i < ARSIZE; i++)
		reverse_string(words[i]);
	show_array(words, ARSIZE);

	return 0;
}
