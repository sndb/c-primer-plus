#include <stdio.h>
#include <stdlib.h>

#define NUM 40

void fillarray(double ar[], int n)
{
	for (int i = 0; i < n; i++)
		ar[i] = (double)rand() / ((double)rand() + 0.1);
}

void showarray(const double ar[], int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%9.4f ", ar[i]);
		if (i % 6 == 5)
			putchar('\n');
	}
	if (i % 6 != 0)
		putchar('\n');
}

int mycomp(const void *p1, const void *p2)
{
	const double *a1 = (const double *)p1;
	const double *a2 = (const double *)p2;

	if (*a1 < *a2)
		return -1;
	else if (*a1 == *a2)
		return 0;
	else
		return 1;
}

int main(void)
{
	double vals[NUM];

	fillarray(vals, NUM);
	puts("Random list:");
	showarray(vals, NUM);
	qsort(vals, NUM, sizeof(double), mycomp);
	puts("\nSorted list:");
	showarray(vals, NUM);

	return 0;
}
