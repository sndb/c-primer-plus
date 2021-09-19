#include <math.h>
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

int deglitch(int ar[][Y], int size, int x, int y)
{
	int diff_side = 0;
	double diff_score = 0;

	// left
	if (x - 1 >= 0) {
		if (abs(ar[x][y] - ar[x - 1][y]) > 1)
			diff_score += ar[x - 1][y];
		else
			return ar[x][y];
		diff_side++;
	}
	// rigth
	if (x + 1 < size) {
		if (abs(ar[x][y] - ar[x + 1][y]) > 1)
			diff_score += ar[x + 1][y];
		else
			return ar[x][y];
		diff_side++;
	}
	// above
	if (y - 1 >= 0) {
		if (abs(ar[x][y] - ar[x][y - 1]) > 1)
			diff_score += ar[x][y - 1];
		else
			return ar[x][y];
		diff_side++;
	}
	// below
	if (y + 1 < Y) {
		if (abs(ar[x][y] - ar[x][y + 1]) > 1)
			diff_score += ar[x][y + 1];
		else
			return ar[x][y];
		diff_side++;
	}

	return (int)rint(diff_score / diff_side);
}

void arcpy2d(int dest[][Y], int src[][Y], int size)
{
	for (int x = 0; x < size; x++)
		for (int y = 0; y < Y; y++)
			dest[x][y] = src[x][y];
}

int main(int argc, char *argv[])
{
	FILE *fp;
	char filename[MAXNAME];
	int data[X][Y];
	int deglitch_buf[X][Y];
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

	// import data from file
	for (int x = 0; x < X; x++)
		for (int y = 0; y < Y; y++)
			if (fscanf(fp, "%d", &data[x][y]) != 1) {
				fprintf(stderr, "Invalid or corrupted data file\n");
				exit(EXIT_FAILURE);
			}

	fclose(fp);

	// deglitch data
	for (int x = 0; x < X; x++)
		for (int y = 0; y < Y; y++)
			deglitch_buf[x][y] = deglitch(data, X, x, y);

	arcpy2d(data, deglitch_buf, X);

	// convert data to pic
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
