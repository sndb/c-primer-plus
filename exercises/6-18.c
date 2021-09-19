#include <stdio.h>

int main(void)
{
	const int DUNBARS_NUMBER = 150;
	int friends = 5;
	int week = 0;

	while (friends < DUNBARS_NUMBER)
	{
		printf("The number of friends in the %d week: %d.\n",
				week, friends);
		week++;
		friends -= week;
		friends *= 2;
	}

	return 0;
}
