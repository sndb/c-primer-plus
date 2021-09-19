#include <stdio.h>

void larger_of(double *x, double *y)
{
	if (*x > *y)
		*y = *x;
	else
		*x = *y;
}

int main(void)
{
	double i1 = 3.0, i2 = 5.0;
	double j1 = 7.0, j2 = 6.0;

	printf("i1 = %g, i2 = %g\n", i1, i2);
	printf("j1 = %g, j2 = %g\n", j1, j2);
	printf("after larger_of:\n");
	larger_of(&i1, &i2);
	larger_of(&j1, &j2);
	printf("i1 = %g, i2 = %g\n", i1, i2);
	printf("j1 = %g, j2 = %g\n", j1, j2);

	return 0;
}
