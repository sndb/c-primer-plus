#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 100

void print_list(const int * list, size_t n)
{
	int period = 4;
	int i;

	for (i = 0; i < n; i++)
	{
		printf("[%2d]: %2d  ", i, list[i]);
		if (i % period == period-1)
			putchar('\n');
	}
	if (i % period != 0)
		putchar('\n');
}

void sort_list(int * list, size_t n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (list[i] < list[j])
			{
				int tmp = list[i];
				list[i] = list[j];
				list[j] = tmp;
			}
		}
	}
}

int main(void)
{
	int number_list[LEN];

	srand(time(0));
	for (int i = 0; i < LEN; i++)
		number_list[i] = rand() % 10 + 1;
	print_list(number_list, LEN);

	sort_list(number_list, LEN);
	puts("\nafter sorting:");
	print_list(number_list, LEN);

	return 0;
}
