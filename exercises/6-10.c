#include <stdio.h>

int main(void)
{
	int lower, upper;
	int sum_of_squares, i;

	printf("Enter lower and upper integer limits: ");
	scanf("%d %d", &lower, &upper);
	while (lower < upper) {
		for (i = lower, sum_of_squares = 0; i <= upper; i++)
		{
			sum_of_squares += i * i;
		}
		printf("The sum of the squares from %d to %d is %d\n",
				lower * lower, upper * upper, sum_of_squares);
		printf("Enter next set of limits: ");
		scanf("%d %d", &lower, &upper);
	}
	printf("Done\n");

	return 0;
}
