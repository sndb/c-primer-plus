#include <stdio.h>
#include <stdlib.h>

double power(double n, int p)
{
	double pow = 1;

	if (n == 0) {
		if (p == 0) {
			printf("0 to the 0 is undefined; using a value of 1\n");
			return 1.0;
		} else {
			return 0;
		}
	}

	for (int i = 1; i <= abs(p); i++)
		pow *= n;

	if (p < 0)
		pow = 1 / pow;

	return pow;
}

int main(void)
{
	printf("%g to the %g is %g\n", 2.0, 5.0, power(2, 5));
	printf("%g to the %g is %g\n", 2.0, -2.0, power(2.0, -2.0));
	printf("%g to the %g is %g\n", 0.0, 0.0, power(0.0, 0.0));
	printf("%g to the %g is %g\n", 0.0, 2.0, power(0.0, 2.0));
}
