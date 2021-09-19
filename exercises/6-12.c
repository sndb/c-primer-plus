#include <stdio.h>

int main(void)
{
	int terms;
	int i;
	float sign;
	float total1;
	float total2;

	scanf("%d", &terms);
	while (terms > 0)
	{
		for (i = 1, sign = 1., total1 = 0., total2 = 0.; i <= terms; i++, sign = -sign)
		{
			total1 += 1./i;
			total2 += 1./i * sign;
		}
		printf("%8.5f  %8.5f\n", total1, total2);

		scanf("%d", &terms);
	}

	return 0;
}
