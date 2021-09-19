#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 256

void map_upper(char *s)
{
	while (*s != '\0') {
		*s = toupper(*s);
		s++;
	}
}

void map_lower(char *s)
{
	while (*s != '\0') {
		*s = tolower(*s);
		s++;
	}
}

int main(int argc, char *argv[])
{
	char buf[BUFSIZE];
	int to_upper = 0;
	int to_lower = 0;

	if (argc < 1 || argc > 2) {
		fprintf(stderr, "Usage: %s [-u, -l, or -p]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if (argc == 2) {
		if (!strcmp("-u", argv[1]))
			to_upper = 1;
		else if (!strcmp("-l", argv[1]))
			to_lower = 1;
		else if (!strcmp("-p", argv[1]))
			;
		else {
			fprintf(stderr, "Usage: %s [-u, -l, or -p]\n", argv[0]);
			exit(EXIT_FAILURE);
		}
	}

	while (fgets(buf, BUFSIZE, stdin)) {
		if (to_upper)
			map_upper(buf);
		else if (to_lower)
			map_lower(buf);
		fputs(buf, stdout);
	}

	return 0;
}
