#include <stdio.h>

int main(void)
{
	float num;

	scanf("%f", &num);
	printf("%.1f, %.1e\n", num, num);
	printf("%+.3f, %.3E\n", num, num);

	return 0;
}
