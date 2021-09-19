#include <stdio.h>

const int DAYS_IN_WEEK = 7;

int main(void)
{
	int days_in, weeks, days;

	printf("Enter number of days (<=0 to exit):\n");
	scanf("%d", &days_in);
	while (days_in > 0)
	{
		weeks = days_in / DAYS_IN_WEEK;
		days = days_in % DAYS_IN_WEEK;
		printf("%d days are %d weeks, %d days.\n", days_in, weeks, days);
		printf("Enter number of days again (<=0 to exit):\n");
		scanf("%d", &days_in);
	}

	return 0;
}
