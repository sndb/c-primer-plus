#include <stdio.h>

int main(void)
{
	int year = 0;
	float chuckie_balance = 1000000;

	while (chuckie_balance > 0)
	{
		year++;
		chuckie_balance -= 100000;
		chuckie_balance += chuckie_balance * 0.08;
		printf("Chuckie's balance: %.2f. Year: %d\n",
				chuckie_balance, year);
	}

	return 0;
}
