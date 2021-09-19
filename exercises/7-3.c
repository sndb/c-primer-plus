#include <stdio.h>

int main(void)
{
	int even_ints = 0;
	int odd_ints = 0;
	int even_total = 0;
	int odd_total = 0;
	int v;

	while (scanf("%d", &v) == 1) {
		if (v == 0)
			break;
		if (v % 2 == 0) {
			even_ints++;
			even_total += v;
		} else {
			odd_ints++;
			odd_total += v;
		}
	}

	if (even_ints)
		printf("Total number of even ints: %d; average: %.2lf\n", even_ints,
		       (double)even_total / even_ints);
	if (odd_ints)
		printf("Total number of odd ints: %d; average: %.2lf\n", odd_ints,
		       (double)odd_total / odd_ints);

	return 0;
}
