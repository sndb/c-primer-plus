#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char c;
	int space_cnt, newline_cnt, other_cnt;
	space_cnt = newline_cnt = other_cnt = 0;

	while ((c = getchar()) != '#')
	{
		if (c == '\n')
			newline_cnt++;
		else if (isspace(c))
			space_cnt++;
		else
			other_cnt++;
	}
	printf("spaces: %d; newlines: %d; other: %d.\n",
			space_cnt, newline_cnt, other_cnt);

	return 0;
}
