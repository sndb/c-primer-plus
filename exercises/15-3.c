#include <stdio.h>

int count_on_bits(int num)
{
	int bits = 0;

	while (num > 0) {
		if (num & 1)
			bits++;
		num >>= 1;
	}

	return bits;
}

int main(void)
{
	printf("The number of 'on' bits in the %d: %d\n", 2, count_on_bits(2));
	printf("The number of 'on' bits in the %d: %d\n", 5, count_on_bits(5));
	printf("The number of 'on' bits in the %d: %d\n", 7, count_on_bits(7));
	printf("The number of 'on' bits in the %d: %d\n", 32, count_on_bits(32));
	printf("The number of 'on' bits in the %d: %d\n", 63, count_on_bits(63));

	return 0;
}
