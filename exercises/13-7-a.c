#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 64

int main(int argc, char *argv[])
{
	FILE *f1, *f2;
	char buf[2][BUFSIZE];

	if (argc != 3) {
		fprintf(stderr, "Usage: %s <filename> <filename>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	f1 = fopen(argv[1], "r");
	f2 = fopen(argv[2], "r");
	if (!f1 || !f2) {
		fprintf(stderr, "Could not open one or both files\n");
		exit(EXIT_FAILURE);
	}

	while (!feof(f1) || !feof(f2)) {
		if (fgets(buf[0], BUFSIZE, f1))
			fputs(buf[0], stdout);
		if (fgets(buf[1], BUFSIZE, f2))
			fputs(buf[1], stdout);
	}

	fclose(f1);
	fclose(f2);

	return 0;
}
