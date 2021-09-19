#include <stdbool.h>
#include <stdio.h>

#define SIZE(X) (sizeof X / sizeof *X)

bool n_in_array(int sorted_ar[], size_t arsize, int n)
{
	size_t ic = arsize / 2;
	size_t imin = 0;
	size_t imax = arsize;
	int c;

	while ((c = sorted_ar[ic]) != n) {
		if (imin == imax)
			return false;

		if (c < n)
			imin = ic + 1;
		else
			imax = ic;

		ic = (imin + imax) / 2;
	}
	return true;
}

int main(void)
{
	int nums[] = {1, 3, 4, 5, 6, 8, 10};

	for (int i = 1; i <= 10; i++)
		printf("%d in array: %s\n", i, n_in_array(nums, SIZE(nums), i) ? "yes" : "no");

	return 0;
}
