#include <stdio.h>

int main(void)
{
	const float KM_IN_MI = 1.609;
	const float L_IN_GAL = 3.785;

	float traveled_mi;
	float gas_gal;
	float mi_per_gal;
	float gas_l;
	float traveled_km;
	float l_per_100km;

	printf("Enter the number of miles traveled: ");
	scanf("%f", &traveled_mi);
	printf("Enter the number of gallons of gasoline consumed: ");
	scanf("%f", &gas_gal);

	mi_per_gal = traveled_mi / gas_gal;

	gas_l = gas_gal * L_IN_GAL;
	traveled_km = traveled_mi * KM_IN_MI;
	l_per_100km = gas_l / traveled_km * 100;

	printf("Miles-per-gallon value: %.1f\n", mi_per_gal);
	printf("Liters-per-100-km value: %.1f\n", l_per_100km);

	return 0;
}
