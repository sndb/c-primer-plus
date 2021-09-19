#include <stdio.h>

#include "s_gets.h"

char *s_gets(char *st, int n)
{
	char *ret;
	int i = 0;

	ret = fgets(st, n, stdin);
	if (ret)
	{
		while (st[i] != '\n' && st[i] != '\0')
			i++;
		if (st[i] == '\n')
			st[i] = '\0';
		else
			while (getchar() != '\n')
				continue;
	}

	return ret;
}
