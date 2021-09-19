#include <stdio.h>

int bstoi(const char *bs)
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

int main(void)
{
	char *pbin = "00011001";

	printf("%s to a numeric value: %d\n", pbin, bstoi(pbin));

	return 0;
}
