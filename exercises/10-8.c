#include <stdio.h>

void copy_arr(double ar_dest[], double ar_src[], int n);

int main(void)
{
	double source[7] = {1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8};
	double dest[3];

	copy_arr(dest, source + 2, 3);
	for (int i = 0; i < 7; i++)
	{
		printf("source[%d]: %f", i, source[i]);
		if (i < 3)
			printf("    dest[%d]: %f", i, dest[i]);
		printf("\n");
	}

	return 0;
}

void copy_arr(double ar_dest[], double ar_src[], int n)
{
	for (int i = 0; i < n; i++)
		ar_dest[i] = ar_src[i];
}
