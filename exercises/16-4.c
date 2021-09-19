#include <stdio.h>
#include <time.h>

void run_delay(double seconds)
{
	clock_t start = clock();

	while (((double)clock() - (double)start) / CLOCKS_PER_SEC < seconds)
		continue;
}

int main(void)
{
	double delay = 5.0;

	printf("Waiting %g seconds...\n", delay);
	run_delay(delay);
	printf("%g seconds has passed!\n", delay);

	return 0;
}
