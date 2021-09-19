#include <stdio.h>

int main(void)
{
	float age_in_years, age_in_seconds;
	float seconds_in_years = 3.156e7;

	printf("Enter your are in years: ");
	scanf("%f", &age_in_years);

	age_in_seconds = age_in_years * seconds_in_years;

	printf("Your age is %f seconds.\n", age_in_seconds);

	return 0;
}
