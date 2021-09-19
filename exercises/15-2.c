#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int bs_to_int(const char *bs)
{
	int r = 0;

	while (*bs) {
		r <<= 1;
		if (*bs == '1')
			r |= 1;
		bs++;
	}

	return r;
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

int main(int argc, char *argv[])
{
	int n1;
	int n2;
	size_t bssize = CHAR_BIT * sizeof(int) + 1;
	char bs[bssize];

	if (argc != 3) {
		fprintf(stderr, "Usage: %s <BIN NUM> <BIN NUM>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	n1 = bs_to_int(argv[1]);
	n2 = bs_to_int(argv[2]);

	printf("~%s = %s\n", argv[1], int_to_bs(bs, bssize, ~n1));
	printf("~%s = %s\n", argv[2], int_to_bs(bs, bssize, ~n2));
	printf("%s & %s = %s\n", argv[1], argv[2], int_to_bs(bs, bssize, n1 & n2));
	printf("%s | %s = %s\n", argv[1], argv[2], int_to_bs(bs, bssize, n1 | n2));
	printf("%s ^ %s = %s\n", argv[1], argv[2], int_to_bs(bs, bssize, n1 ^ n2));

	return 0;
}
