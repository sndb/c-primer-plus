#include <stdio.h>

int main(void)
{
	float cm_in_inch = 2.54;
	float height_cm;
	float height_inch;

	printf("Enter your height in centimeters: ");
	scanf("%f", &height_cm);

	height_inch = height_cm / cm_in_inch;
	printf("Your height in inches is %f\n.", height_inch);

	return 0;
}
