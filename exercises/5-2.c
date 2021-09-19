#include <stdio.h>

int main(void)
{
	int i, n;

	printf("Enter an integer: ");
	scanf("%d", &i);
	n = i + 10;
	while (i <= n) {
		printf("%d\n", i);
		i++;
	}

	return 0;
}
