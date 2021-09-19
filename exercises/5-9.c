#include <stdio.h>

void Temperatures(double f);

int main(void)
{
	double fahr;

	printf("Enter a Fahrenheit temperature: ");
	while (scanf("%lf", &fahr) == 1)
	{
		Temperatures(fahr);
		printf("Enter next temperature in Fahrenheit ('q' to quit): ");
	}

	return 0;
}

void Temperatures(double f)
{
	const double celsius_ratio = 5.0 / 9.0;
	const double celsius_subtrahend = 32.0;
	const double kelvin_addend = 273.16;

	double c, k;

	c = celsius_ratio * (f - celsius_subtrahend);
	k = c + kelvin_addend;
	printf("F: %.2f; C: %.2f; K: %.2f.\n", f, c, k);
}
