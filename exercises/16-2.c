#include <stdio.h>

#define HARMONIC(X, Y) (2 / (((1 / (X)) + (1 / (Y)))))

int main(void)
{
	double x = 2.0;
	double y = 3.0;

	printf("Harmonic mean of %g and %g is %g.\n", x, y, HARMONIC(x, y));

	return 0;
}
