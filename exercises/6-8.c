#include <stdio.h>

int main(void)
{
	float f1, f2;

	while (scanf(" %f %f", &f1, &f2) == 2)
	{
		printf("%f\n", (f1-f2)/(f1*f2));
	}

	return 0;
}
