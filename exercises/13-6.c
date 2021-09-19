#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 256

char *getname(char *name, size_t n)
{
	char *s = fgets(name, n, stdin);
	if (s)
	{
		char *ch = strchr(name, '\n');
		if (ch)
			*ch = '\0';
	}
	return s;
}

int main(void)
{
	FILE *in;
	FILE *out;
	char src[LEN];
	char dst[LEN];
	int ch;
	int count = 0;

	printf("Enter the filename: ");
	getname(src, LEN);

	if ((in = fopen(src, "r")) == NULL)
	{
		fprintf(stderr, "I couldn't open the file \"%s\"\n", src);
		exit(EXIT_FAILURE);
	}

	strncpy(dst, src, LEN-5);
	dst[LEN - 5]  = '\0';
	strcat(dst, ".red");

	if ((out = fopen(dst, "w")) == NULL)
	{
		fprintf(stderr, "Can't create output file\n");
		exit(3);
	}

	while ((ch = getc(in)) != EOF)
		if (count++ % 3 == 0)
			putc(ch, out);

	if (fclose(in) != 0 || fclose(out) != 0)
		fprintf(stderr, "Error in closing files\n");

	return 0;
}
