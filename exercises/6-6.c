#include <stdio.h>

int main(void)
{
	int lower, upper;

	printf("Enter lower and upper limits for the table: ");
	for (scanf("%d%d", &lower, &upper); lower <= upper; lower++)
	{
		printf("%4d %4d %4d\n", lower, lower * lower, lower * lower * lower);
	}

	return 0;
}
