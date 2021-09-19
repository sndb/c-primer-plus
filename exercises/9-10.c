#include <stdio.h>

void to_base_n(unsigned long n, unsigned int base)
{
	if (n >= base)
		to_base_n(n / base, base);
	printf("%lu", n % base);
}

int main(void)
{
	unsigned long number;
	unsigned int base;

	printf("Enter an integer and a base (q to quit):\n");
	while (scanf("%lu %u", &number, &base) == 2) {
		printf("Base-%d equivalent: ", base);
		to_base_n(number, base);
		putchar('\n');
		printf("Enter an integer (q to quit):\n");
	}
	printf("Done.\n");

	return 0;
}
