#include <stdio.h>

int max(int ar[], int n);

int main(void)
{
	int array[5] = { 3, 2, 5, 4, 1 };
	printf("the largest value stored in an array is %d\n", max(array, 5));
	return 0;
}

int max(int ar[], int n)
{
	int r = ar[0];

	for (int i = 1; i < n; i++)
	{
		if (ar[i] > r)
			r = ar[i];
	}

	return r;
}
