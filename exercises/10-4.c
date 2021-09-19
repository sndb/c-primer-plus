#include <stdio.h>

int max(double ar[], int n);

int main(void)
{
	double array[5] = { 3.21, 3.2, 6.0, 2.5, 4.4 };
	printf("the largest value's index is %d\n", max(array, 5));
	return 0;
}

int max(double ar[], int n)
{
	int r = 0;

	for (int i = 1; i < n; i++)
	{
		if (ar[i] > ar[r])
			r = i;
	}

	return r;
}
