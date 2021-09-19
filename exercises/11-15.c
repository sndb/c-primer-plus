#include <ctype.h>
#include <stdio.h>

int to_integer(const char *s)
{
	int num = 0;

	while (*s != '\0') {
		if (isdigit(*s)) {
			num *= 10;
			num += (*s - '0');
		} else
			return 0;
		s++;
	}

	return num;
}

int main(int argc, char *argv[])
{
	int num;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <NUM>\n", argv[0]);
		return 1;
	}
	num = to_integer(argv[1]);
	printf("You entered number %d.\n", num);

	return 0;
}
