#include <stdio.h>
#include <string.h>

#include "s_gets_strchr.h"

char *s_gets(char *st, int n)
{
	char *ret;

	ret = fgets(st, n, stdin);
	if (ret)
	{
		st = strchr(st, '\n');
		if (st)
			*st = '\0';
		else
			while (getchar() != '\n')
				continue;
	}

	return ret;
}
