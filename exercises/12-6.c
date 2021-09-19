#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clean_numbers(unsigned int * numbers, size_t n)
{
	for (size_t i = 0; i < n; i++)
		numbers[i] = 0;
}

void count_numbers(unsigned int * numbers, size_t n, size_t count)
{
	for (size_t i = 0; i < count; i++)
		numbers[rand() % n]++;
}

void print_numbers(unsigned int * numbers, size_t n)
{
	for (size_t i = 0; i < n; i++)
		printf("Number %zu was produced %d times.\n", i+1, numbers[i]);
}

int main(void)
{
	const size_t count = 1000;
	const size_t len = 10;
	unsigned int numbers[len];

	for (size_t i = 0; i < 10; i++)
	{
		printf("Pass %zu:\n", i+1);
		srand(i + 42);
		clean_numbers(numbers, len);
		count_numbers(numbers, len, count);
		print_numbers(numbers, len);
		if (i != 9)
			putchar('\n');
	}

	return 0;
}
