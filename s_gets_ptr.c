#include <stdio.h>

#include "s_gets_ptr.h"

char *s_gets(char *st, int n)
{
	char *ret;

	ret = fgets(st, n, stdin);
	if (ret)
	{
		while (*st != '\n' && *st != '\0')
			st++;
		if (*st == '\n')
			*st = '\0';
		else
			while (getchar() != '\n')
				continue;
	}

	return ret;
}
