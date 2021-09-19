#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ** get_words(size_t n)
{
	char ** words = (char **) malloc(n * sizeof(char *));
	char word[256];

	if (words)
		for (size_t i = 0; i < n; i++)
			if (scanf("%s", word) == 1
			&& (words[i] = (char *) malloc((strlen(word)+1) * sizeof(char))))
				strcpy(words[i], word);
	return words;
}

void display_words(char ** words, size_t n)
{
	for (size_t i = 0; i < n; i++)
		printf("%s\n", words[i]);
}

void dealloc_words(char ** words, size_t n)
{
	if (words)
	{
		for (size_t i = 0; i < n; i++)
			if (words[i])
				free(words[i]);
		free(words);
	}
}

int main(void)
{
	char ** words;
	size_t q;

	printf("How many words do you wish to enter? ");
	scanf("%zd", &q);
	printf("Enter %zd words now:\n", q);
	words = get_words(q);
	if (words)
	{
		display_words(words, q);
		dealloc_words(words, q);
	}

	return 0;
}
