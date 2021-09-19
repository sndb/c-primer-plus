#include <ctype.h>
#include <stdio.h>

int main(void)
{
	char ch;
	int uppercnt = 0;
	int lowercnt = 0;
	int othercnt = 0;

	while ((ch = getchar()) != EOF) {
		if (isupper(ch))
			uppercnt++;
		else if (islower(ch))
			lowercnt++;
		else
			othercnt++;
	}
	printf(
	    "There is %d uppercase characters, %d lowercase characters, and %d other characters.\n",
	    uppercnt, lowercnt, othercnt);

	return 0;
}
