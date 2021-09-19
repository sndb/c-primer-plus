#include <stdio.h>

#define STOP '#'

int main(void)
{
	char c;
	unsigned c_cnt = 0;

	while ((c = getchar()) != STOP)
	{
		c_cnt++;
		printf("'%c': %3d ", c, c);
		if (c_cnt % 8 == 0)
			putchar('\n');
	}
	putchar('\n');

	return 0;
}
