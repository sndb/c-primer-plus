#include <stdio.h>

void sort(double *n1, double *n2, double *n3)
{
	double tmp;

	if (*n1 > *n2) {
		tmp = *n1;
		*n1 = *n2;
		*n2 = tmp;
	}
	if (*n1 > *n3) {
		tmp = *n1;
		*n1 = *n3;
		*n3 = tmp;
	}
	if (*n2 > *n3) {
		tmp = *n2;
		*n2 = *n3;
		*n3 = tmp;
	}
}

int main(void)
{
	double n1 = 5.0, n2 = 3.0, n3 = 4.2;
	double j1 = 3.2, j2 = 8.2, j3 = 5.6;

	printf("n1 = %g, n2 = %g, n3 = %g\n", n1, n2, n3);
	printf("j1 = %g, j2 = %g, j3 = %g\n", j1, j2, j3);
	printf("sorting...\n");
	sort(&n1, &n2, &n3);
	sort(&j1, &j2, &j3);
	printf("n1 = %g, n2 = %g, n3 = %g\n", n1, n2, n3);
	printf("j1 = %g, j2 = %g, j3 = %g\n", j1, j2, j3);

	return 0;
}
