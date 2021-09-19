#include <stdio.h>

extern int rnd(void);
extern void srnd(unsigned int seed);

int main(void)
{
	int count;
	unsigned seed;

	printf("Please enter your choice for seed.\n");
	while (scanf("%u", &seed) == 1)
	{
		srnd(seed);
		for (count = 0; count < 5; count++)
			printf("%d\n", rnd());
		printf("Please enter next seed (q to quit):\n");
	}
	printf("Done.\n");

	return 0;
}
