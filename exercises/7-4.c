#include <stdio.h>

int main(void)
{
	char c;
	int substc = 0;

	while ((c = getchar()) != '#') {
		if (c == '.') {
			putchar('!');
			substc++;
		} else if (c == '!') {
			putchar('!');
			putchar('!');
			substc++;
		} else
			putchar(c);
	}
	printf("\nThe number of substitutions was made is %d\n", substc);

	return 0;
}
