#include <ctype.h>
#include <stdio.h>

#define BUFSIZE 256

void remove_spaces(char *s)
{
	char *w = s;
	while (*s) {
		if (!isspace(*s)) {
			*w = *s;
			w++;
		}
		s++;
	}
	*w = '\0';
}

int main(void)
{
	char buf[BUFSIZE];
	while (fgets(buf, 256, stdin)) {
		if (*buf == '\n')
			break;
		remove_spaces(buf);
		printf("%s\n", buf);
	}
}
