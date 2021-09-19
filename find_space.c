#include <stdio.h>

char *find_space(const char *s)
{
	while (*s != ' ') {
		if (!*s) {
			s = NULL;
			break;
		}
		s++;
	}

	return (char *)s;
}

int main(void)
{
	const char *s = "how you?";
	const char *f;

	f = find_space(s);
	if (f)
		printf("%s\n", f);
	else
		printf("There is no spaces!\n");

	return 0;
}
