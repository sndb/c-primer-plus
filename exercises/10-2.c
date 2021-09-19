#include <stdio.h>

#define LENGTH 5

void copy_arr(double ar_dest[], double ar_src[], int n);
void copy_ptr(double * ar_dest, double * ar_src, int n);
void copy_ptrs(double * ar_dest, double * ar_src, double * ar_src_end);

int main(void)
{
	double source[LENGTH] = {1.1, 2.2, 3.3, 4.4, 5.5};
	double target1[LENGTH];
	double target2[LENGTH];
	double target3[LENGTH];

	copy_arr(target1, source, LENGTH);
	copy_ptr(target2, source, LENGTH);
	copy_ptrs(target3, source, source + LENGTH);

	for (int i = 0; i < LENGTH; i++)
		printf("%5f %5f %5f %5f\n", source[i], target1[i], target2[i], target3[i]);

	return 0;
}

void copy_arr(double ar_dest[], double ar_src[], int n)
{
	for (int i = 0; i < n; i++)
		ar_dest[i] = ar_src[i];
}

void copy_ptr(double * ar_dest, double * ar_src, int n)
{
	for (int i = 0; i < n; i++)
		*(ar_dest + i) = *(ar_src + i);
}

void copy_ptrs(double * ar_dest, double * ar_src, double * ar_src_end)
{
	for (double * ptr = ar_src; ptr < ar_src_end; ar_dest++, ptr++)
		*ar_dest = *ptr;
}
