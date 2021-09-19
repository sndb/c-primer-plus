#include <ctype.h>
#include <stdio.h>

void clearinput(void)
{
	while (getchar() != '\n')
		continue;
}

char getfirst(void)
{
	int ch;

	while (!isalpha(ch = getchar()))
		continue;
	clearinput();

	return ch;
}

float getnumber(void)
{
	float n;
	char ch;

	while (scanf("%f", &n) != 1) {
		while ((ch = getchar()) != '\n')
			putchar(ch);
		printf(" is not a number.\n"
		       "Please enter a number, such as 2.5, -1.78E8, or 3: ");
	}
	clearinput();

	return n;
}

char getmenuchoice(void)
{
	char ch;

	printf("Enter the operation of your choice:\n");
	printf("a. add         s. subtract\n");
	printf("m. multiply    d. divide\n");
	printf("q) quit\n");
	ch = getfirst();

	return ch;
}

void askfornumbers(float *n1, float *n2)
{
	printf("Enter first number: ");
	*n1 = getnumber();
	printf("Enter second number: ");
	*n2 = getnumber();
}

int main(void)
{
	char ch;
	float n1, n2;

	while ((ch = getmenuchoice()) != 'q') {
		switch (ch) {
		case 'a':
			askfornumbers(&n1, &n2);
			printf("%g + %g = %g\n", n1, n2, n1 + n2);
			break;
		case 's':
			askfornumbers(&n1, &n2);
			printf("%g - %g = %g\n", n1, n2, n1 - n2);
			break;
		case 'm':
			askfornumbers(&n1, &n2);
			printf("%g * %g = %g\n", n1, n2, n1 * n2);
			break;
		case 'd':
			askfornumbers(&n1, &n2);
			while (n2 == 0) {
				printf("Enter a number other than 0: ");
				n2 = getnumber();
			}
			printf("%g / %g = %g\n", n1, n2, n1 / n2);
			break;
		default:
			printf("You should enter one of the letters: a, b, c, d, or q.\n");
			break;
		}
	}
	printf("Bye.\n");
	return 0;
}
