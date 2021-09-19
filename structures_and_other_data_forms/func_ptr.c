#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LEN 81

char *s_gets(char *st, int n);
char showmenu(void);
void eatline(void);
void show(void (*fp)(char *), char *str);
void ToUpper(char *str);
void ToLower(char *str);
void Transpose(char *str);
void Dummy(char *str);

int main(void)
{
	char line[LEN];
	char copy[LEN];
	char choice;
	void (*pfun)(char *);

	puts("Enter a string (empty line to quit):");
	while(s_gets(line, LEN) && line[0])
	{
		while ((choice = showmenu()) != 'n')
		{
			switch (choice)
			{
				case 'u':
					pfun = ToUpper;
					break;
				case 'l':
					pfun = ToLower;
					break;
				case 't':
					pfun = Transpose;
					break;
				case 'o':
					pfun = Dummy;
					break;
			}
			strcpy(copy, line);
			show(pfun, copy);
		}
		puts("Enter a string (empty line to quit):");
	}
	puts("Bye!");

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

char showmenu(void)
{
	char ans;

	puts("Enter menu choice:");
	puts("u) uppercase       l) lowercase");
	puts("t) transposed case o) original case");
	puts("n) next string");
	ans = tolower(getchar());
	eatline();
	while (!strchr("ulton", ans))
	{
		puts("Please enter a u, l, t, o, or n:");
		ans = tolower(getchar());
		eatline();
	}

	return ans;
}

void eatline(void)
{
	while (getchar() != '\n')
		continue;
}

void show(void (*fp)(char *), char *str)
{
	fp(str);
	puts(str);
}

void ToUpper(char *str)
{
	while (*str)
	{
		*str = toupper(*str);
		str++;
	}
}

void ToLower(char *str)
{
	while (*str)
	{
		*str = tolower(*str);
		str++;
	}
}

void Transpose(char *str)
{
	while (*str)
	{
		if (islower(*str))
			*str = toupper(*str);
		else if (isupper(*str))
			*str = tolower(*str);
		str++;
	}
}

void Dummy(char *str)
{
}
