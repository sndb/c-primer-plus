#include <stdio.h>

double cube(double x);

int main(void)
{
	double num;

	printf("Enter the number: ");
	scanf("%lf", &num);
	printf("%lf\n", cube(num));

	return 0;
}

double cube(double x)
{
	x = x * x * x;
	return x;
}
