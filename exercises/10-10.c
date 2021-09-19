#include <stdio.h>

void sumar(int srcar1[], int srcar2[], int dstar[], int n);

int main(void)
{
	int ar1[4] = {2, 4, 5, 8};
	int ar2[4] = {1, 0, 4, 6};
	int ar3[4];

	sumar(ar1, ar2, ar3, 4);
	printf("%6s %6s %6s\n", "ar1", "ar2", "ar3");
	for (int i = 0; i < 4; i++)
		printf("%6d %6d %6d\n", ar1[i], ar2[i], ar3[i]);

	return 0;
}

void sumar(int srcar1[], int srcar2[], int dstar[], int n)
{
	for (int i = 0; i < n; i++)
		 dstar[i] = srcar1[i] + srcar2[i];
}
