#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNAME 256

void fprintpic(FILE *stream, int xres, int yres, char pic[xres][yres + 1])
{
	for (int x = 0; x < xres; x++)
		fprintf(stream, "%s\n", pic[x]);
}

int main(int argc, char *argv[])
{
	FILE *fp;
	char filename[MAXNAME];
	int xres;
	int yres;
	const char *conv = " .':~*=&%#";

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <FILE>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	printf("Enter the data file resolution (in 'x y' format): ");
	if (scanf("%d %d", &xres, &yres) != 2) {
		fprintf(stderr, "Invalid file resolution\n");
		exit(EXIT_FAILURE);
	}
	int data[xres][yres];
	char pic[xres][yres + 1];

	if (!(fp = fopen(argv[1], "r"))) {
		fprintf(stderr, "Usage: %s <FILE>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	for (int x = 0; x < xres; x++)
		for (int y = 0; y < yres; y++)
			if (fscanf(fp, "%d", &data[x][y]) != 1) {
				fprintf(stderr, "Invalid or corrupted data file\n");
				exit(EXIT_FAILURE);
			}

	fclose(fp);

	for (int x = 0; x < xres; x++) {
		for (int y = 0; y < yres; y++)
			pic[x][y] = conv[data[x][y]];
		pic[x][yres] = '\0';
	}

	fprintpic(stdout, xres, yres, pic);

	strncpy(filename, argv[1], MAXNAME - 5);
	filename[MAXNAME - 5] = '\0';
	strcat(filename, ".pic");
	if (!(fp = fopen(filename, "w"))) {
		fprintf(stderr, "Could not open %s for writing\n", filename);
		exit(EXIT_FAILURE);
	}

	fprintpic(fp, xres, yres, pic);

	fclose(fp);

	return 0;
}
