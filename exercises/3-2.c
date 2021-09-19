#include <stdio.h>

int main(void)
{
	int code;

	printf("Enter an ASCII code value: ");
	scanf("%d", &code);
	printf("Character having that ASCII code: %c\n", code);

	return 0;
}
