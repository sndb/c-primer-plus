#include <stdio.h>

int mystrlen(const char *s)
{
	int ct = 0;

	while (*s++)
		ct++;

	return ct;
}
