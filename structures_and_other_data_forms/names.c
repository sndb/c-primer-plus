#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SLEN 81

struct namect {
	char *fname;
	char *lname;
	int letters;
};

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

void getinfo(struct namect *pst)
{
	char temp[SLEN];

	printf("Please enter your first name.\n");
	s_gets(temp, SLEN);
	pst->fname = (char *) malloc(strlen(temp) + 1);
	strcpy(pst->fname, temp);

	printf("Please enter your last name.\n");
	s_gets(temp, SLEN);
	pst->lname = (char *) malloc(strlen(temp) + 1);
	strcpy(pst->lname, temp);
}

void makeinfo(struct namect *pst)
{
	pst->letters = strlen(pst->fname) + strlen(pst->lname);
}

void showinfo(const struct namect *pst)
{
	printf("%s %s, your name contains %d letters.\n", pst->fname, pst->lname, pst->letters);
}

void cleanup(struct namect *pst)
{
	free(pst->fname);
	free(pst->lname);
}

int main(void)
{
	struct namect person;

	getinfo(&person);
	makeinfo(&person);
	showinfo(&person);
	cleanup(&person);

	return 0;
}
