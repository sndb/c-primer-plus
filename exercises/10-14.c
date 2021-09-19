#include <stdio.h>

#define X 3
#define Y 5

void getInput(int x, int y, double ar[x][y])
{
	printf("Enter %d sets of %d double numbers each\n", x, y);
	for (int ix = 0; ix < x; ix++)
		for (int iy = 0; iy < y; iy++)
			scanf("%lf", &ar[ix][iy]);
}

double getAverage(int x, double ar[x])
{
	double r = 0;
	for (int i = 0; i < x; i++)
		r += ar[i];
	r /= x;
	return r;
}

double getAverage2D(int x, int y, double ar[x][y])
{
	double r = 0;
	for (int ix = 0; ix < x; ix++)
		for (int iy = 0; iy < y; iy++)
			r += ar[ix][iy];
	r /= x * y;
	return r;
}

double getLargest(int x, int y, double ar[x][y])
{
	double r = ar[0][0];
	for (int ix = 0; ix < x; ix++)
		for (int iy = 0; iy < y; iy++)
			if (ar[ix][iy] > r)
				r = ar[ix][iy];
	return r;
}

void reportResults(int x, double averages[x], double allAverage, double largest)
{
	printf("Averages of each set of five values: ");
	for (int i = 0; i < x; i++)
		printf("%.2lf ", averages[i]);
	printf("\nAverage of all the values: %.2lf\n", allAverage);
	printf("The largest value: %.2lf\n", largest);
}

int main(void)
{
	double ar[X][Y];
	double averages[X];
	double allAverage;
	double largest;

	getInput(X, Y, ar);
	for (int ix = 0; ix < X; ix++)
		averages[ix] = getAverage(Y, ar[ix]);
	allAverage = getAverage2D(X, Y, ar);
	largest = getLargest(X, Y, ar);
	reportResults(X, averages, allAverage, largest);

	return 0;
}
