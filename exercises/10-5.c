#include <stdio.h>

double diff(double ar[], int n);

int main(void)
{
	double array[5] = { 3.21, 3.2, 6.0, 2.5, 4.4 };
	printf("the difference between the largest and smallest elements\n"
		"of an array is %.2f\n", diff(array, 5));
	return 0;
}

double diff(double ar[], int n)
{
	int smallest_i = 0;
	int largest_i = 0;

	for (int i = 1; i < n; i++)
	{
		if (ar[i] < ar[smallest_i])
			smallest_i = i;
		if (ar[i] > ar[largest_i])
			largest_i = i;
	}

	return ar[largest_i] - ar[smallest_i];
}
