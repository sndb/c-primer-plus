#include <stdio.h>

#define PAYRATE1 8.75
#define PAYRATE2 9.33
#define PAYRATE3 10.00
#define PAYRATE4 11.20

#define OVERTIMEHOURS 40
#define OVERTIMERATE 1.5

#define TAXRATE1 0.15
#define TAXRATE2 0.20
#define TAXRATE3 0.25

#define TAXMARGIN1 300.0
#define TAXMARGIN2 450.0

void clearinput(void)
{
	while (getchar() != '\n')
		continue;
}

int getpayrate(double *payrate)
{
	int n;

	printf("*****************************************************************\n");
	printf("Enter the number corresponding to the desired pay rate or action:\n");
	printf("%-33s%-33s\n", "1) $8.75/hr", "2) $9.33/hr");
	printf("%-33s%-33s\n", "3) $10.00/hr", "4) $11.20/hr");
	printf("%-33s\n", "5) quit");
	printf("*****************************************************************\n");
	scanf("%d", &n);
	clearinput();
	while (n < 1 || n > 5) {
		printf("You should enter the number between 1 and 5: ");
		scanf("%d", &n);
		clearinput();
	}

	switch (n) {
	case 1:
		*payrate = PAYRATE1;
		break;
	case 2:
		*payrate = PAYRATE2;
		break;
	case 3:
		*payrate = PAYRATE3;
		break;
	case 4:
		*payrate = PAYRATE4;
		break;
	case 5:
		return 0;
	}
	return 1;
}

int main(void)
{
	int hours;
	double payrate;
	double gross;
	double taxes;
	double net;

	while (getpayrate(&payrate)) {
		printf("Enter the hours worked in a week: ");
		scanf("%d", &hours);
		if (hours > OVERTIMEHOURS)
			hours = OVERTIMEHOURS + (hours - OVERTIMEHOURS) * OVERTIMERATE;

		gross = hours * payrate;

		if (gross > TAXMARGIN2)
			taxes = TAXMARGIN1 * TAXRATE1 + (TAXMARGIN2 - TAXMARGIN1) * TAXRATE2 +
				(gross - TAXMARGIN2) * TAXRATE3;
		else if (gross > TAXMARGIN1)
			taxes = TAXMARGIN1 * TAXRATE1 + (gross - TAXMARGIN1) * TAXRATE2;
		else
			taxes = gross * TAXRATE1;

		net = gross - taxes;

		printf("Gross pay: %.2lf; taxes: %.2lf, net pay: %.2lf.\n", gross, taxes, net);
	}

	return 0;
}
