#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	double n;
	int p;

	if (argc != 3) {
		fprintf(stderr, "Usage: %s <NUMBER> <POWER>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	n = atof(argv[1]);
	p = atoi(argv[2]);

	printf("%lf\n", pow(n, p));

	return 0;
}
