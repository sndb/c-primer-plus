#include <stdio.h>

double min(double x, double y) { return x < y ? x : y; }

int main(void)
{
	double x, y;

	scanf("%lf %lf", &x, &y);
	printf("the smaller of %g and %g is %g\n", x, y, min(x, y));

	return 0;
}
