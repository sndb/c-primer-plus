#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LEN 256

bool hasc(char c, const char *line)
{
	while (*line)
	{
		if (*line == c)
			return true;
		line++;
	}
	return false;
}

int main(int argc, char *argv[])
{
	FILE *fp;
	char line[LEN];

	if (argc != 3)
	{
		fprintf(stderr, "Usage: %s <character> <filename>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if (!(fp = fopen(argv[2], "r")))
	{
		fprintf(stderr, "Can't open the file");
		exit(EXIT_FAILURE);
	}

	while (fgets(line, LEN, fp))
		if (hasc(*argv[1], line))
			fputs(line, stdout);

	fclose(fp);

	return 0;
}
