#include <stdio.h>

#define FIRST 0.15
#define EXCESS 0.28

#define CAT1 17850
#define CAT2 23900
#define CAT3 29750
#define CAT4 14875

void clearinput(void)
{
	while (getchar() != '\n')
		continue;
}

int reqinput(int *category, double *income)
{
	printf("1) Single, %.2f%% of first %d plus %.2f%% of excess\n", FIRST * 100, CAT1,
	       EXCESS * 100);
	printf("2) Head of Household, %.2f%% of first %d plus %.2f%% of excess\n", FIRST * 100,
	       CAT2, EXCESS * 100);
	printf("3) Married, Joint, %.2f%% of first %d plus %.2f%% of excess\n", FIRST * 100, CAT3,
	       EXCESS * 100);
	printf("4) Married, Separate, %.2f%% of first %d plus %.2f%% of excess\n", FIRST * 100,
	       CAT4, EXCESS * 100);

	printf("Enter the tax category ('q' to quit): ");
	if (scanf("%d", category) != 1)
		return 0;

	printf("Enter the taxable income: ");
	while (scanf("%lf", income) != 1 || *income < 0) {
		printf("You should enter the positive number: ");
	}

	return 1;
}

int main(void)
{
	int category;
	double income;
	double sum;

	while (reqinput(&category, &income)) {
		if (category < 1 || category > 4) {
			printf("Your should enter the valid number.\n");
			continue;
		}
		switch (category) {
		case 1:
			sum = CAT1;
			break;
		case 2:
			sum = CAT2;
			break;
		case 3:
			sum = CAT3;
			break;
		case 4:
			sum = CAT4;
			break;
		}
		if (income > sum)
			printf("Tax: %.2lf\n", FIRST * sum + EXCESS * (income - sum));
		else
			printf("Tax: %.2lf\n", FIRST * income);
	}

	return 0;
}
