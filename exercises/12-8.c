#include <stdio.h>
#include <stdlib.h>

int * make_array(size_t n, int v)
{
	int * ar = (int *) malloc(n * sizeof(int));
	if (ar)
		for (size_t i = 0; i < n; i++)
			ar[i] = v;
	return ar;
}

void show_array(const int ar[], size_t n)
{
	size_t i;
	for (i = 0; i < n; i++)
	{
		printf("%4d ", ar[i]);
		if (i % 8 == 7)
			putchar('\n');
	}
	if (i % 8 != 0)
		putchar('\n');
}

int main(void)
{
	int * pa;
	size_t size;
	int value;

	printf("Enter the number of elements: ");
	while (scanf("%zd", &size) == 1 && size > 0)
	{
		printf("Enter the initialization value: ");
		scanf("%d", &value);
		pa = make_array(size, value);
		if (pa)
		{
			show_array(pa, size);
			free(pa);
		}
		printf("Enter the number of elements (<1 to quit): ");
	}
	printf("Done.\n");
	return 0;
}
