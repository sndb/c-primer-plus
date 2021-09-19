#include <stdio.h>

#define CM_IN_FEET 30.48
#define CM_IN_INCH 2.54

int main(void)
{
	float centimeters;
	int feet;
	float inches;

	printf("Enter a height in centimeters: ");
	scanf("%f", &centimeters);
	while (centimeters > 0)
	{
		feet = centimeters / CM_IN_FEET;
		inches = (centimeters - feet * CM_IN_FEET) / CM_IN_INCH;
		printf("%.1f cm = %d feet, %.1f inches.\n",
				centimeters, feet, inches);
		printf("Enter a height in centimeters (<=0 to quit): ");
		scanf("%f", &centimeters);
	}

	printf("bye\n");
	return 0;
}
