#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	double sum = 0;
	double tmp;
	int c = 0;

	if (argc == 2)
		fp = fopen(argv[1], "r");
	else
		fp = stdin;

	if (!fp) {
		fprintf(stderr, "Can't open an input file\n");
		exit(EXIT_FAILURE);
	}

	while (fscanf(fp, "%lf", &tmp) == 1) {
		sum += tmp;
		c++;
	}
	if (c > 0)
		printf("The average of %d entered numbers is %.2lf\n", c, sum / c);
	else {
		fprintf(stderr, "No valid data\n");
		exit(EXIT_FAILURE);
	}

	fclose(fp);

	return 0;
}
