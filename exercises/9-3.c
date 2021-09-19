#include <stdio.h>

void print_square(char ch, int times, int lines)
{
	for (int i = 0; i < lines; i++) {
		for (int j = 0; j < times; j++)
			putchar(ch);
		putchar('\n');
	}
}

int main(void)
{
	print_square('x', 6, 8);

	return 0;
}
