#include <stdio.h>

#define PAYRATE 10
#define OVERTIMEHOURS 40
#define OVERTIMERATE 1.5

#define TAXRATE1 0.15
#define TAXRATE2 0.20
#define TAXRATE3 0.25

#define TAXMARGIN1 300.0
#define TAXMARGIN2 450.0

int main(void)
{
	int hours;
	double gross;
	double taxes;
	double net;

	printf("Enter the hours worked in a week: ");
	scanf("%d", &hours);
	if (hours > OVERTIMEHOURS)
		hours = OVERTIMEHOURS + (hours - OVERTIMEHOURS) * OVERTIMERATE;

	gross = hours * 10;

	if (gross > TAXMARGIN2)
		taxes = TAXMARGIN1 * TAXRATE1 + (TAXMARGIN2 - TAXMARGIN1) * TAXRATE2 +
			(gross - TAXMARGIN2) * TAXRATE3;
	else if (gross > TAXMARGIN1)
		taxes = TAXMARGIN1 * TAXRATE1 + (gross - TAXMARGIN1) * TAXRATE2;
	else
		taxes = gross * TAXRATE1;

	net = gross - taxes;

	printf("Gross pay: %.2lf; taxes: %.2lf, net pay: %.2lf.\n", gross, taxes, net);

	return 0;
}
