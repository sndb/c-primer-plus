#include <stdio.h>

int main(void)
{
	float wtr_q;
	float mols_in_wtr;
	float wtr_mol_m = 3.0e-23;
	float gr_in_q = 950.;

	printf("Enter an amount of water in quarts: ");
	scanf("%f", &wtr_q);

	mols_in_wtr = wtr_q * gr_in_q / wtr_mol_m;

	printf("The number of water molecules in that amount is %e.\n", mols_in_wtr);

	return 0;
}
