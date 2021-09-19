#include <stdio.h>

int get_bit(int num, int pos) { return (num & (1 << pos)) == (1 << pos); }

int main(void)
{
	printf("Number: %d; bit position: %d; value: %d\n", 2, 0, get_bit(2, 0));
	printf("Number: %d; bit position: %d; value: %d\n", 5, 2, get_bit(5, 2));
	printf("Number: %d; bit position: %d; value: %d\n", 7, 1, get_bit(7, 1));
	printf("Number: %d; bit position: %d; value: %d\n", 32, 6, get_bit(32, 6));
	printf("Number: %d; bit position: %d; value: %d\n", 63, 3, get_bit(63, 3));

	return 0;
}
