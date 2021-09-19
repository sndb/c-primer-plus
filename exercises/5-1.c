#include <stdio.h>

const int MINS_IN_HOUR = 60;

int main(void)
{
	int time;
	int mins;
	int hours;

	printf("Enter time in minutes (<=0 to exit):\n");
	scanf("%d", &time);
	while (time > 0)
	{
		hours = time / MINS_IN_HOUR;
		mins = time % MINS_IN_HOUR;
		printf("%d hours, %d minutes.\n", hours, mins);
		printf("Enter time in minutes (<=0 to exit):\n");
		scanf("%d", &time);
	}

	return 0;
}
