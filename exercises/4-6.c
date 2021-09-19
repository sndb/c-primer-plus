#include <stdio.h>
#include <string.h>

int main(void)
{
	char first[40];
	char last[40];
	int first_len;
	int last_len;

	printf("Enter your name: ");
	scanf("%s %s", first, last);
	first_len = strlen(first);
	last_len = strlen(last);
	printf("%s %s\n", first, last);
	printf("%*d %*d\n\n", first_len, first_len, last_len, last_len);
	printf("%s %s\n", first, last);
	printf("%-*d %-*d\n", first_len, first_len, last_len, last_len);

	return 0;
}
