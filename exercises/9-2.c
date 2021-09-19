#include <stdio.h>

void chline(char ch, int i, int j)
{
	int n = j - i;
	while (--i > 0)
		putchar(' ');
	while (n-- >= 0) {
		putchar(ch);
	}
	putchar('\n');
}

int main(void)
{
	chline('x', 4, 9);
	chline('y', 2, 5);
	chline('z', 20, 30);

	return 0;
}
