#include <stdio.h>

int main(void)
{
	const int A_LENGTH = 8;
	int a[A_LENGTH];
	int i;

	for (i = 0; i < A_LENGTH; i++)
	{
		scanf("%d", &a[i]);
	}

	for (i = 1; i <= A_LENGTH; i++)
	{
		printf("%d ", a[A_LENGTH - i]);
	}
	printf("\nDone\n");

	return 0;
}
