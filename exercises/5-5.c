#include <stdio.h>

int main(void)
{
	int count, sum, far;

	count = 0;
	sum = 0;
	printf("How far the calculation should proceed: ");
	scanf("%d", &far);
	while (count++ < far)
		sum = sum + count;
	printf("sum = %d\n", sum);
	
	return 0;
}
