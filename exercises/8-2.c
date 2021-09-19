#include <stdio.h>

int main(void)
{
	char ch;
	int count = 0;

	while ((ch = getchar()) != EOF) {
		if (ch == '\n') {
			printf("'\\n': %d\n", ch);
			count = 0;
		} else if (ch == '\t')
			printf("'\\t': %d, ", ch);
		else if (ch < ' ')
			printf("'^%c': %d, ", ch + 64, ch);
		else
			printf("'%c': %d, ", ch, ch);
		count++;
		if (count % 10 == 0)
			putchar('\n');
	}
	if (count % 10 != 0)
		putchar('\n');

	return 0;
}
