#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 256

int main(int argc, char *argv[])
{
	FILE *fp;
	char s[SIZE];

	if (argc != 3) {
		fprintf(stderr, "Usage: %s <STRING> <FILENAME>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if (!(fp = fopen(argv[2], "r"))) {
		fprintf(stderr, "Could not open the file\n");
		exit(EXIT_FAILURE);
	}

	while (fgets(s, SIZE, fp)) {
		if (strstr(s, argv[1]))
			fputs(s, stdout);
	}

	fclose(fp);

	return 0;
}
