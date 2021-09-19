#include <stdio.h>

int main(void)
{
	float height;
	float height_converted;
	char name[50];

	printf("Enter your height in centimeters: ");
	scanf("%f", &height);
	height_converted = height / 100.;
	printf("Enter your name: ");
	scanf("%s", name);
	printf("%s, you are %.2f meters tall.\n", name, height_converted);

	return 0;
}
