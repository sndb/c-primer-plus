#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct month {
	char name[20];
	char abbr[3];
	int ndays;
	int mnum;
};

int howmanydays(int m);
int getmonth(char *m);
int isleap(int m);
void ToLower(char *s);
char *s_gets(char *s, int n);

const struct month year[12] = {
	{ "january",   "jan", 31, 1  },
	{ "february",  "feb", 28, 2  },
	{ "march",     "mar", 31, 3  },
	{ "april",     "apr", 30, 4  },
	{ "may",       "may", 31, 5  },
	{ "june",      "jun", 30, 6  },
	{ "jule",      "jul", 31, 7  },
	{ "august",    "aug", 31, 8  },
	{ "september", "sep", 30, 9  },
	{ "october",   "oct", 31, 10 },
	{ "november",  "nov", 30, 11 },
	{ "december",  "dec", 31, 12 }
};

int main(void)
{
	char m_s[20];
	int d;
	int m;
	int y;
	int total;

	printf("Enter the day, month, and year: ");
	scanf("%d %s %d", &d, m_s, &y);

	ToLower(m_s);
	m = getmonth(m_s);
	if (m < 0)
	{
		fprintf(stderr, "Can't recognize that month\n");
		exit(EXIT_FAILURE);
	}
	total = d + howmanydays(m);
	if (isleap(y) && m > 1)
		total++;

	printf("The total number of days in the year up throught the given day is %d\n", total);

	return 0;
}

int howmanydays(int m)
{
	int total = 0;

	for (int i = 0; i < m; i++)
	{
		total += year[i].ndays;
	}

	return total;
}

int getmonth(char *m)
{
	char smnum[3];
	int f = -1;

	for (size_t i = 0; i < sizeof year; i++)
	{
		sprintf(smnum, "%d", year[i].mnum);
		if (strcmp(year[i].name, m) == 0
		|| strcmp(year[i].abbr, m) == 0
		|| strcmp(smnum, m) == 0)
		{
			f = i;
			break;
		}
	}

	return f;
}

int isleap(int m)
{
	if (m % 4 == 0 && m % 100 != 0)
		return 1;
	return 0;
}

void ToLower(char *s)
{
	while (*s)
	{
		*s = tolower(*s);
		s++;
	}
}

char *s_gets(char *s, int n)
{
	char *r = fgets(s, n, stdin);
	char *find;

	if (r)
	{
		find = strchr(s, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}

	return r;
}
