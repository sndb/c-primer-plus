#include <stdio.h>
#include "12-3-a.h"

int main(void)
{
	int mode;
	int choice;
	float distance;
	float fuel_consumed;

	printf("Enter 0 for metric mode, 1 for US mode: ");
	scanf("%d", &choice);
	while (choice >= 0)
	{
		set_mode(&mode, choice);
		get_info(mode, &distance, &fuel_consumed);
		show_info(mode, distance, fuel_consumed);
		printf("Enter 0 for metric mode, 1 for US mode (-1 to quit): ");
		scanf("%d", &choice);
	}
	printf("Done.\n");

	return 0;
}
