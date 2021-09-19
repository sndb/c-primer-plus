#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "12-7b.h"

void clean_input(void)
{
	while (getchar() != '\n')
		continue;
}

int main(void)
{
	int roll;
	int dice;
	int sides;
	int status;
	int sets;

	srand((unsigned int) time(0));

	printf("Enter the number of sets; enter q to stop: ");
	while(scanf("%d", &sets) == 1 && sets > 0)
	{
		int i;

		printf("How many sides and how many dice? ");
		if ((status = scanf("%d %d", &sides, &dice)) != 2)
		{
			if (status == EOF)
				break;
			else
			{
				printf("You should have entered integers. Let's begin again.\n");
				clean_input();
				printf("Enter the number of sets; enter q to stop: ");
				continue;
			}
		}

		printf("Here are %d sets of %d %d-sided throws.\n", sets, dice, sides);
		for (i = 0; i < sets; i++)
		{
			roll = roll_n_dice(dice, sides);
			printf("%3d ", roll);
			if (i % 10 == 9)
				putchar('\n');
		}
		if (i % 10 != 0)
			putchar('\n');

		printf("How many sets? Enter q to stop: ");
	}

	printf("The rollem() function was called %d times.\n", roll_count);
	printf("GOOD FORTUNE TO YOU!\n");

	return 0;
}
