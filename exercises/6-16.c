#include <stdio.h>

int main(void)
{
	int year = 0;
	const double ORIGINAL_INVESTMENT = 100.;
	double daphne_balance = ORIGINAL_INVESTMENT;
	double deirdre_balance = ORIGINAL_INVESTMENT;

	printf("Daphne    Deirdre    Year\n");
	while (daphne_balance >= deirdre_balance)
	{
		year++;
		daphne_balance += ORIGINAL_INVESTMENT * 0.1;
		deirdre_balance += deirdre_balance * 0.05;
		printf("%6.2f    %7.2f    %4d\n",
				daphne_balance, deirdre_balance, year);
	}

	return 0;
}
