#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define X 20
#define Y 30
#define MAXNAME 256

void fprintpic(FILE *stream, char pic[][Y + 1], int x)
{
	for (int i = 0; i < x; i++)
		fprintf(stream, "%s\n", pic[i]);
}

int main(int argc, char *argv[])
{
	FILE *fp;
	char filename[MAXNAME];
	int data[X][Y];
	char pic[X][Y + 1];
	const char *conv = " .':~*=&%#";

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <FILE>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if (!(fp = fopen(argv[1], "r"))) {
		fprintf(stderr, "Usage: %s <FILE>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	for (int x = 0; x < X; x++)
		for (int y = 0; y < Y; y++)
			if (fscanf(fp, "%d", &data[x][y]) != 1) {
				fprintf(stderr, "Invalid or corrupted data file\n");
				exit(EXIT_FAILURE);
			}

	fclose(fp);

	for (int x = 0; x < X; x++) {
		for (int y = 0; y < Y; y++)
			pic[x][y] = conv[data[x][y]];
		pic[x][Y] = '\0';
	}

	fprintpic(stdout, pic, X);

	strncpy(filename, argv[1], MAXNAME - 5);
	filename[MAXNAME - 5] = '\0';
	strcat(filename, ".pic");
	if (!(fp = fopen(filename, "w"))) {
		fprintf(stderr, "Could not open %s for writing\n", filename);
		exit(EXIT_FAILURE);
	}

	fprintpic(fp, pic, X);

	fclose(fp);

	return 0;
}
