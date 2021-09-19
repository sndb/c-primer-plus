#include <stdio.h>

int main(void)
{
	char c;
	char prev = '\0';
	int count = 0;

	while ((c = getchar()) != '#') {
		if (prev == 'e' && c == 'i')
			count++;
		prev = c;
	}
	printf("The sequence 'ei' was repeated %d times.\n", count);

	return 0;
}
