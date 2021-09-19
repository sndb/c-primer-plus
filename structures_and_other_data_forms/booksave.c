#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTITL 41
#define MAXAUTL 41
#define MAXBKS 5

char *s_gets(char *st, int n);

struct book {
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

int main(void)
{
	struct book library[MAXBKS];
	int c = 0;
	int i;
	int filecount;
	FILE *pbooks;
	int size = sizeof(struct book);

	if (!(pbooks = fopen("book.dat", "a+b")))
	{
		fputs("Can't open book.dat file\n", stderr);
		exit(1);
	}

	rewind(pbooks);
	while (c < MAXBKS && fread(&library[c], size, 1, pbooks) == 1)
	{
		if (c == 0)
			puts("Current contents of book.dat:");
		printf("%s by %s: $%.2f\n", library[c].title, library[c].author, library[c].value);
		c++;
	}
	filecount = c;
	if (c == MAXBKS)
	{
		fputs("The book.dat file is full.\n", stderr);
		exit(2);
	}

	puts("Please add new book titles.");
	puts("Press [enter] at the start of a line to stop.");
	while (c < MAXBKS && s_gets(library[c].title, MAXTITL) && library[c].title[0])
	{
		puts("Now enter the author.");
		s_gets(library[c].author, MAXAUTL);
		puts("Now enter the value.");
		scanf("%f", &library[c].value);
		c++;
		while (getchar() != '\n')
			continue;
		if (c < MAXBKS)
			printf("Enter the next title.\n");
	}

	if (c > 0)
	{
		printf("Here is the list of your books:\n");
		for (i = 0; i < c; i++)
			printf("%s by %s: $%.2f\n", library[i].title, library[i].author, library[i].value);
		fwrite(&library[filecount], size, c - filecount, pbooks);
	}
	else
		printf("No books? Too bad.\n");

	puts("Bye.");
	fclose(pbooks);

	return 0;
}

char *s_gets(char *st, int n)
{
	char *ret_val;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		st = strchr(st, '\n');
		if (st)
			*st = '\0';
		else
			while (getchar() != '\n')
				continue;
	}

	return ret_val;
}
