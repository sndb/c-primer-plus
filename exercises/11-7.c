#include <stdio.h>

#define SRCARSIZE (sizeof src_words / sizeof *src_words)
#define WORDLEN 6

char *mystrncpy(char *dest, const char *src, size_t n)
{
	int pad = 0;

	for (size_t i = 0; i < n; i++) {
		if (!pad && src[i] == '\0')
			pad = 1;
		if (pad)
			dest[i] = '\0';
		else
			dest[i] = src[i];
	}

	return dest;
}

int main(void)
{
	char *src_words[] = {"apple", "banana", "peach", "orange"};
	char dst_words[SRCARSIZE][WORDLEN];

	for (size_t i = 0; i < SRCARSIZE; i++) {
		printf("Copying %s from src_words[%zd] to dst_words[%zd]...\n", src_words[i], i, i);
		mystrncpy(dst_words[i], src_words[i], WORDLEN);
		dst_words[i][WORDLEN - 1] = '\0';
		printf("Result: src_words[%zd] = %s, dst_words[%zd] = %s\n", i, src_words[i], i,
		       dst_words[i]);
		if (i != SRCARSIZE - 1)
			putchar('\n');
	}

	return 0;
}
