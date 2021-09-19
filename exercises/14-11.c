#include <math.h>
#include <stdio.h>

#define SIZE 100

void transform(double source[], double target[], int n, double (*f)(double))
{
	for (int i = 0; i < n; i++)
		target[i] = f(source[i]);
}

void printar(double ar[], int n)
{
	int i;
	for (i = 0; i < n; i++) {
		printf("%7.2lf ", ar[i]);
		if (i % 10 == 9)
			putchar('\n');
	}
	if (i % 10 != 0)
		putchar('\n');
}

double func1(double x) { return -x; }

double func2(double x) { return x - (1 / x); }

int main(void)
{
	double ar1[SIZE];
	double ar2[SIZE];

	// init ar1
	for (int i = 0; i < SIZE; i++)
		ar1[i] = i + 1;
	printf("original:\n");
	printar(ar1, SIZE);

	// math.h, sqrt
	transform(ar1, ar2, SIZE, sqrt);
	printf("sqrt:\n");
	printar(ar2, SIZE);

	// math.h, sin
	transform(ar1, ar2, SIZE, sin);
	printf("sin:\n");
	printar(ar2, SIZE);

	// my, func1
	transform(ar1, ar2, SIZE, func1);
	printf("func1:\n");
	printar(ar2, SIZE);

	// my, func2
	transform(ar1, ar2, SIZE, func2);
	printf("func2:\n");
	printar(ar2, SIZE);

	return 0;
}
