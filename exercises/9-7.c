#include <ctype.h>
#include <stdio.h>

int find_alpha_loc(char ch)
{
	if (!isalpha(ch))
		return -1;

	return tolower(ch) - 'a' + 1;
}

int main(void)
{
	char ch;
	int loc;

	while ((ch = getchar()) != EOF)
		if ((loc = find_alpha_loc(ch)) != -1)
			printf("numerical location of %c in the alphabet: %d\n", ch, loc);

	return 0;
}
