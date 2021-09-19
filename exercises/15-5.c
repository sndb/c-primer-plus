#include <limits.h>
#include <stdio.h>

unsigned int rotate_left(unsigned int num, int places)
{
	const unsigned int high_bit_mask = 1 << (CHAR_BIT * sizeof(unsigned int) - 1);
	int high_bit;

	while (places > 0) {
		high_bit = (num & high_bit_mask) == high_bit_mask;
		num <<= 1;
		num |= high_bit;
		places--;
	}

	return num;
}

char *int_to_bs(char *bs, size_t size, int n)
{
	for (int i = size - 2; i >= 0; i--) {
		bs[i] = (n & 1) == 1 ? '1' : '0';
		n >>= 1;
	}
	bs[size - 1] = '\0';

	return bs;
}

int main(void)
{
	size_t bssize = CHAR_BIT * sizeof(int) + 1;
	char bs[bssize];

	printf("Rotating %u by %u bits to the left: %u\n", 0, 2, rotate_left(0, 2));
	printf("Rotating %u by %u bits to the left: %u\n", -1, 5, rotate_left(-1, 5));
	printf("Rotating %u by %u bits to the left: %u\n", 64, 3, rotate_left(64, 3));
	printf("Rotating %u by %u bits to the left: %u\n", UINT_MAX, 1, rotate_left(UINT_MAX, 1));
	printf("Rotating %u by %u bits to the left: %u\n", INT_MAX, 1, rotate_left(INT_MAX, 1));
	printf("%s\n", int_to_bs(bs, bssize, INT_MAX));
	printf("%s\n", int_to_bs(bs, bssize, rotate_left(INT_MAX, 1)));

	return 0;
}
