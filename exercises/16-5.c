#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void print_selected_numbers(int ar[], size_t n, size_t picks)
{
	size_t p;

	if (picks > n) {
		fprintf(stderr, "Number of picks can not be larger than the size of the array\n");
		exit(EXIT_FAILURE);
	}

	for (size_t i = 0; i < picks; i++) {
		p = rand() % n;
		printf("%d ", ar[p]);
		n--;
		if (p != n)
			memmove(ar + p, ar + p + 1, sizeof(int) * (n - p));
	}
	putchar('\n');
}

int main(void)
{
	int ar[] = {2, 8, 7, 15, 9, 4, 1};

	srand(time(0));
	print_selected_numbers(ar, sizeof ar / sizeof *ar, 3);

	return 0;
}
