#include <stdio.h>

unsigned int countself(void)
{
	static unsigned int count = 0;
	return ++count;
}

int main(void)
{
	for (int i = 0; i < 100; i++)
		printf("I have been called %u times.\n", countself());

	return 0;
}
