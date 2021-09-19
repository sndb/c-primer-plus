#include <stdio.h>

void printar(const int ar[][5], int n);
void doublear(int ar[][5], int n);

int main(void)
{
	int ar1[3][5] = {
		{1, 2, 3, 10, 20},
		{4, 5, 6, 11, 21},
		{7, 8, 9, 12, 22}
	};

	printf("before doublear call:\n");
	printar(ar1, 3);

	printf("after doublear call:\n");
	doublear(ar1, 3);
	printar(ar1, 3);

	return 0;
}

void printar(const int ar[][5], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 5; j++)
			printf("%3d ", ar[i][j]);
		putchar('\n');
	}
}

void doublear(int ar[][5], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 5; j++)
			ar[i][j] = ar[i][j] * 2;
}
