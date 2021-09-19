#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LIM 256

void die(const char *msg)
{
	fprintf(stderr, "%s\n", msg);
	exit(EXIT_FAILURE);
}

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
	char fsrcname[LIM];
	char fdstname[LIM];
	FILE *fsrc;
	FILE *fdst;
	char ch;

	printf("Enter the name of the source file: ");
	if (!getname(fsrcname, LIM) || !(fsrc = fopen(fsrcname, "r")))
		die("Can't open the source file");

	printf("Enter the name of the output file: ");
	if (!getname(fdstname, LIM) || !(fdst = fopen(fdstname, "w")))
		die("Can't open the output file");

	while ((ch = getc(fsrc)) != EOF)
		putc(toupper(ch), fdst);

	fclose(fsrc);
	fclose(fdst);

	return 0;
}
