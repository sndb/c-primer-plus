#include <stdio.h>

int main(void)
{
	float pints, cups, ounces, tablespoons, teaspoons;

	printf("Enter a volume in cups: ");
	scanf("%f", &cups);

	pints = cups / 2;
	ounces = cups * 8;
	tablespoons = ounces * 2;
	teaspoons = tablespoons * 3;

	printf("Pints: %f\n", pints);
	printf("Ounces: %f\n", ounces);
	printf("Tablespoons: %f\n", tablespoons);
	printf("Teaspoons: %f\n", teaspoons);

	return 0;
}
