#include <stdio.h>

#define X 3
#define Y 5

void getInput(double ar[][Y], int n)
{
	printf("Enter %d sets of five double numbers each\n", n);
	for (int x = 0; x < n; x++)
		for (int y = 0; y < Y; y++)
			scanf("%lf", &ar[x][y]);
}

double getAverage(double ar[], int x)
{
	double r = 0;
	for (int i = 0; i < x; i++)
		r += ar[i];
	r /= x;
	return r;
}

double getAverage2D(double ar[][Y], int x)
{
	double r = 0;
	for (int i = 0; i < x; i++)
		for (int y = 0; y < Y; y++)
			r += ar[i][y];
	r /= x * Y;
	return r;
}

double getLargest(double ar[][Y], int x)
{
	double r = ar[0][0];
	for (int i = 0; i < x; i++)
		for (int y = 0; y < Y; y++)
			if (ar[i][y] > r)
				r = ar[i][y];
	return r;
}

void reportResults(double averages[], int n, double allAverage, double largest)
{
	printf("Averages of each set of five values: ");
	for (int i = 0; i < n; i++)
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

	getInput(ar, X);
	for (int i = 0; i < X; i++)
		averages[i] = getAverage(ar[i], Y);
	allAverage = getAverage2D(ar, X);
	largest = getLargest(ar, X);
	reportResults(averages, X, allAverage, largest);

	return 0;
}
