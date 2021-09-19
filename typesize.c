#include <stdio.h>
#include <inttypes.h>

int main(void)
{
	printf("Type char has a size of %zd bytes.\n", sizeof(char));
	printf("Type short has a size of %zd bytes.\n", sizeof(short));
	printf("Type int has a size of %zd bytes.\n", sizeof(int));
	printf("Type long has a size of %zd bytes.\n", sizeof(long));
	printf("Type long long has a size of %zd bytes.\n", sizeof(long long));
	printf("Type float has a size of %zd bytes.\n", sizeof(float));
	printf("Type double has a size of %zd bytes.\n", sizeof(double));
	printf("Type long double has a size of %zd bytes.\n", sizeof(long double));
	printf("Type int_fast16_t has a size of %zd bytes.\n\n", sizeof(int_fast16_t));

	return 0;
}
