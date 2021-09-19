#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTITL 41
#define MAXAUTL 41
#define MAXBKS 100

struct book {
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

int comparbooktitle(const void *b1, const void *b2);
int comparbookvalue(const void *b1, const void *b2);
char *s_gets(char *st, int n);

int main(void)
{
	struct book library[MAXBKS];
	struct book *l_sorted[MAXBKS];
	int c = 0;
	int i;

	printf("Please enter the book title.\n");
	printf("Press [enter] at the start of a line to stop.\n");
	while (c < MAXBKS && s_gets(library[c].title, MAXTITL) && library[c].title[0])
	{
		printf("Now enter the author.\n");
		s_gets(library[c].author, MAXAUTL);
		printf("Now enter the value.\n");
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
		{
			l_sorted[i] = &library[i];
			printf("%s by %s: $%.2f\n", library[i].title, library[i].author, library[i].value);
		}

		printf("Alphabetized by title:\n");
		qsort(l_sorted, c, sizeof(struct book *), comparbooktitle);
		for (i = 0; i < c; i++)
			printf("%s by %s: $%.2f\n", l_sorted[i]->title, l_sorted[i]->author, l_sorted[i]->value);

		printf("In order of increased value:\n");
		qsort(l_sorted, c, sizeof(struct book *), comparbookvalue);
		for (i = 0; i < c; i++)
			printf("%s by %s: $%.2f\n", l_sorted[i]->title, l_sorted[i]->author, l_sorted[i]->value);
	}
	else
		printf("No books? Too bad.\n");

	return 0;
}

int comparbooktitle(const void *b1, const void *b2)
{
	return strcmp((*(struct book * const *) b1)->title, (*(struct book * const *) b2)->title);
}

int comparbookvalue(const void *b1, const void *b2)
{
	int r;
	if ((*(struct book * const *) b1)->value > (*(struct book * const *) b2)->value)
		r = 1;
	else if ((*(struct book * const *) b1)->value < (*(struct book * const *) b2)->value)
		r = -1;
	else
		r = 0;
	return -r;
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
