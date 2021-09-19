#include <stdio.h>
#include <string.h>

#define MAXTITL 41
#define MAXAUTL 41
#define MAXBKS 100

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
			printf("%s by %s: $%.2f\n", library[i].title, library[i].author, library[i].value);
	}
	else
		printf("No books? Too bad.\n");

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
