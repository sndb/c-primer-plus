#include <stdio.h>

#define LEN_X 3
#define LEN_Y 3

void copy_arr(double ar_dest[], double ar_src[], int n);

int main(void)
{
	double ar[LEN_X][LEN_Y] = { {1.2, 2.3, 3.4}, {2.4, 3.3, 4.2}, {3.3, 4.4, 5.5} };
	double second[LEN_X][LEN_Y];

	for (int i = 0; i < LEN_X; i++)
		copy_arr(second[i], ar[i], LEN_X);

	for (int x = 0; x < LEN_X; x++)
		for (int y = 0; y < LEN_Y; y++)
			printf("source: %.2f | dest: %.2f\n", ar[x][y], second[x][y]);

	return 0;
}

void copy_arr(double ar_dest[], double ar_src[], int n)
{
	for (int i = 0; i < n; i++)
		ar_dest[i] = ar_src[i];
}
