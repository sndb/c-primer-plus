#include <ctype.h>
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

char get_first(void)
{
	int ch;

	while (!isalpha(ch = getchar()))
		continue;
	clearinput();

	return ch;
}

int getpayrate(double *payrate)
{
	char ch;
	int r = 1;

	printf("*****************************************************************\n");
	printf("Enter the number corresponding to the desired pay rate or action:\n");
	printf("%-33s%-33s\n", "a) $8.75/hr", "b) $9.33/hr");
	printf("%-33s%-33s\n", "c) $10.00/hr", "d) $11.20/hr");
	printf("%-33s\n", "q) quit");
	printf("*****************************************************************\n");
	ch = get_first();

	switch (ch) {
	case 'a':
		*payrate = PAYRATE1;
		break;
	case 'b':
		*payrate = PAYRATE2;
		break;
	case 'c':
		*payrate = PAYRATE3;
		break;
	case 'd':
		*payrate = PAYRATE4;
		break;
	case 'q':
		r = 0;
		break;
	default:
		printf("You should enter one of the letters: a, b, c, d, or q.\n");
		r = getpayrate(payrate);
	}
	return r;
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
