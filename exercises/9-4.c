#include <stdio.h>

double harmonic_mean(double n1, double n2) { return 2 / (1 / n1 + 1 / n2); }

int main(void)
{
	printf("harmonic mean of %g and %g is %g\n", 2.0, 5.0, harmonic_mean(2.0, 5.0));

	return 0;
}
