#include <stdio.h>

int main(void)
{
	char c;
	int substc = 0;

	while ((c = getchar()) != '#') {
		switch (c) {
		case '.':
			putchar('!');
			substc++;
			break;
		case '!':
			putchar('!');
			putchar('!');
			substc++;
			break;
		default:
			putchar(c);
			break;
		}
	}
	printf("\nThe number of substitutions was made is %d\n", substc);

	return 0;
}
