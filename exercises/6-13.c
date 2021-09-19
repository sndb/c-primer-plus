#include <stdio.h>

int square(int num, int power);

int main(void)
{
	const int ARR_LEN = 8;
	int arr[ARR_LEN];
	int i;

	for (i = 0; i < ARR_LEN; i++)
	{
		arr[i] = square(2, i);
	}

	i = 0;
	do {
		printf("%d ", arr[i]);
		i++;
	} while (i < ARR_LEN);
	printf("\nDone\n");

	return 0;
}

int square(int num, int power)
{
	int i;
	int result = 1;

	for (i = 0; i < power; i++)
	{
		result *= num;
	}

	return result;
}
