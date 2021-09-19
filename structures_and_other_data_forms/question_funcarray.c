#include <stdio.h>

double f1(double x, double y);
double f2(double x, double y);
double f3(double x, double y);
double f4(double x, double y);

int main(void)
{
	double (*arfp[4])(double, double) = {f1, f2, f3, f4};

	arfp[1](10.0, 2.5);
	(*arfp[1])(10.0, 2.5);

	return 0;
}

double f1(double x, double y)
{
	printf("%g\n", x + y);
	return x + y;
}

double f2(double x, double y)
{
	printf("%g\n", x * y);
	return x + y;
}

double f3(double x, double y)
{
	printf("%g\n", x / y);
	return x + y;
}

double f4(double x, double y)
{
	printf("%g\n", x - y);
	return x + y;
}
