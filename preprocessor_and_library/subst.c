#include <stdio.h>

#define PSQRT(x) printf("The square of " #x " is %d.\n", ((x)*(x)))

int main(void)
{
	int y = 5;
	PSQRT(y);
	PSQRT(2 + 4);

	return 0;
}
