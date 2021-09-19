#include <stdio.h>

int main(void)
{
	const int A_LENGTH = 8;
	double a1[A_LENGTH];
	double a2[A_LENGTH];
	int i;
	double sum;

	for (i = 0; i < A_LENGTH; i++)
	{
		scanf("%lf", &a1[i]);
	}

	for (i = 0, sum = 0; i < A_LENGTH; i++)
	{
		sum += a1[i];
		a2[i] = sum;
	}

	for (i = 0; i < A_LENGTH; i++)
	{
		printf("%6.2f ", a1[i]);
	}
	printf("\n");

	for (i = 0; i < A_LENGTH; i++)
	{
		printf("%6.2f ", a2[i]);
	}
	printf("\n");

	return 0;
}
