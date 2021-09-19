#include <stdio.h>

float calc(float f1, float f2);

int main(void)
{
	float f1, f2;

	while (scanf(" %f %f", &f1, &f2) == 2)
	{
		printf("%f\n", calc(f1, f2));
	}

	return 0;
}

float calc(float f1, float f2)
{
	return (f1-f2)/(f1*f2);
}
