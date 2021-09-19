#include <stdio.h>

int main(void)
{
	int ch_cnt = 0;

	while (getchar() != EOF)
		ch_cnt++;
	printf("%d\n", ch_cnt);

	return 0;
}
