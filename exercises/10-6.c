#include <stdio.h>

#define LENGTH 5

void reverse(double ar[], int n);

int main(void)
{
	double array[LENGTH] = { 3.21, 3.2, 6.0, 2.5, 4.4 };
	reverse(array, LENGTH);
	for (int i = 0; i < LENGTH; i++)
		printf("%f\n", array[i]);
	return 0;
}

void reverse(double ar[], int l)
{
	double tmp;
	for (int i = 0, n = l - 1; n - i > 0; i++, n--)
	{
		tmp = ar[n];
		ar[n] = ar[i];
		ar[i] = tmp;
	}
}
