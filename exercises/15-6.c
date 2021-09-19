#include <stdio.h>

struct font {
	unsigned int id : 8;
	unsigned int size : 7;
	unsigned int alignment : 2;
	unsigned int bold : 1;
	unsigned int italic : 1;
	unsigned int underline : 1;
};

const char *alignments[] = {"left", "center", "right"};

void clear_input(void)
{
	while (getchar() != '\n')
		continue;
}

void display_font_parameters(struct font f)
{
	printf(" ID SIZE ALIGNMENT   B   I   U\n");
	printf("%3d %4d %9s  %3s %3s %3s\n", f.id, f.size, alignments[f.alignment],
	       f.bold ? "on" : "off", f.italic ? "on" : "off", f.underline ? "on" : "off");
}

char get_char(void)
{
	char c;

	while (scanf("%c", &c) != 1) {
		printf("You should enter the letter: ");
		clear_input();
	}
	clear_input();

	return c;
}

int get_num(void)
{
	int n;

	while (scanf("%d", &n) != 1 && n < 0) {
		printf("You should enter the positive number: ");
		clear_input();
	}
	clear_input();

	return n;
}

int main(void)
{
	struct font f = {1, 12, 0, 0, 0, 0};
	char c;
	int n;

	while (1) {
		display_font_parameters(f);
		printf("f) change font    s) change size    a) change alignment\n");
		printf("b) toggle bold    i) toggle italic  u) toggle underline\n");
		printf("q) quit\n");
		c = get_char();
		if (c == 'q')
			break;
		switch (c) {
		case 'f':
			printf("Enter font ID (0-255): ");
			n = get_num();
			f.id = n & ((1 << 9) - 1);
			break;
		case 's':
			printf("Enter font size (0-127): ");
			n = get_num();
			f.size = n & ((1 << 8) - 1);
			break;
		case 'a':
			printf("Select alignment:\n");
			printf("l) left    c) center    r) right\n");
			c = get_char();
			if (c == 'l')
				f.alignment = 0;
			else if (c == 'c')
				f.alignment = 1;
			else if (c == 'r')
				f.alignment = 2;
			else
				printf("You should enter one of the letters: l, c, or r.\n");
			break;
		case 'b':
			f.bold ^= 1;
			break;
		case 'i':
			f.italic ^= 1;
			break;
		case 'u':
			f.underline ^= 1;
			break;
		default:
			printf("Enter one of the letters: f, s, a, b, i, u, or q.\n");
		}
	}
	printf("Bye!\n");

	return 0;
}
