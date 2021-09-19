#include <stdio.h>

void copyar(int n, int m, const double srcar[n][m], double dstar[n][m]);
void printar(int n, int m, const double ar[n][m]);

int main(void)
{
	double ar1[3][5] = {
		{1.1, 2.2, 3.3, 10.1, 20.2},
		{4.4, 5.5, 6.6, 11.1, 21.2},
		{7.7, 8.8, 9.9, 12.1, 22.2}
	};
	double ar2[3][5];

	copyar(3, 5, ar1, ar2);

	printf("source array:\n");
	printar(3, 5, ar1);

	printf("destination array:\n");
	printar(3, 5, ar2);

	return 0;
}

void copyar(int n, int m, const double srcar[n][m], double dstar[n][m])
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			dstar[i][j] = srcar[i][j];
}

void printar(int n, int m, const double ar[n][m])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			printf("%g ", ar[i][j]);
		putchar('\n');
	}
}
