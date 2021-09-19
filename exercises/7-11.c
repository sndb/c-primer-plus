#include <stdio.h>

void clearinput(void)
{
	while (getchar() != '\n')
		continue;
}

char get_letter(void)
{
	char c;
	printf("Enter the letter:\n"
	       "a) artichokes\n"
	       "b) beets\n"
	       "c) carrots\n"
	       "q) quit\n");
	while (scanf("%c", &c) != 1) {
		printf("You should enter the letter.\n");
		clearinput();
	}
	clearinput();
	return c;
}

int get_number(char *s)
{
	int q;
	printf("Enter the pounds of %s desired: ", s);
	while (scanf("%d", &q) != 1 || q < 0) {
		printf("Your should enter the positive number.\n");
		clearinput();
	}
	clearinput();
	return q;
}

double calc_shipping(int pounds)
{
	double r;
	if (pounds > 20)
		r = 14.00 + (pounds - 20) * 0.50;
	else if (pounds > 5)
		r = 14.00;
	else
		r = 6.50;
	return r;
}

double calc_discount(int gross) { return (gross) > 100 ? 0.05 : 0.00; }

int main(void)
{
	int artichokes = 0;
	int beets = 0;
	int carrots = 0;
	char c;
	int quitflag = 0;
	int total_pounds;
	double shipping;
	double artichokes_cost;
	double beets_cost;
	double carrots_cost;
	double gross;
	double discount;
	double grand_total;

	while (!quitflag && (c = get_letter())) {
		switch (c) {
		case 'a':
			artichokes += get_number("artichokes");
			break;
		case 'b':
			beets += get_number("beets");
			break;
		case 'c':
			carrots += get_number("carrots");
			break;
		case 'q':
			quitflag = 1;
			break;
		default:
			printf("You should enter a, b, c, or q.\n");
			break;
		}
	}
	total_pounds = artichokes + beets + carrots;
	shipping = calc_shipping(total_pounds);

	artichokes_cost = artichokes * 2.05;
	beets_cost = beets * 1.15;
	carrots_cost = carrots * 1.09;

	gross = artichokes_cost + beets_cost + carrots_cost;
	discount = calc_discount(gross);
	grand_total = shipping + gross - (gross * discount);
	printf("Info:\n"
	       "Cost per pound: %.2lf\n"
	       "Pounds ordered: %d\n"
	       "Cost for each vegetable:\n"
	       "\tartichokes: %.2lf\n"
	       "\tbeets: %.2lf\n"
	       "\tcarrots: %.2lf\n"
	       "Total cost of the order: %.2lf\n"
	       "Discount: %.2lf\n"
	       "Shipping charge: %.2lf\n"
	       "Grand total: %.2lf\n",
	       gross / total_pounds, total_pounds, artichokes_cost, beets_cost, carrots_cost, gross,
	       gross * discount, shipping, grand_total);

	return 0;
}
