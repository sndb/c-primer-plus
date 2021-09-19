#include <stdio.h>

#define ID_SHIFT 0
#define SIZE_SHIFT 8
#define ALIGNMENT_SHIFT 15
#define STYLE_SHIFT 17

#define ID_MASK (0xFF << ID_SHIFT)
#define SIZE_MASK (0x7F << SIZE_SHIFT)
#define ALIGNMENT_MASK (0x3 << ALIGNMENT_SHIFT)
#define BOLD_MASK (0x1 << STYLE_SHIFT)
#define ITALIC_MASK (0x2 << STYLE_SHIFT)
#define UNDERLINE_MASK (0x4 << STYLE_SHIFT)

const char *alignments[] = {"left", "center", "right"};

void clear_input(void)
{
	while (getchar() != '\n')
		continue;
}

void display_font_parameters(unsigned long f)
{
	printf(" ID SIZE ALIGNMENT   B   I   U\n");
	printf("%3lu %4lu %9s  %3s %3s %3s\n", f & ID_MASK, (f & SIZE_MASK) >> SIZE_SHIFT,
	       alignments[(f & ALIGNMENT_MASK) >> ALIGNMENT_SHIFT],
	       (f & BOLD_MASK) == BOLD_MASK ? "on" : "off",
	       (f & ITALIC_MASK) == ITALIC_MASK ? "on" : "off",
	       (f & UNDERLINE_MASK) == UNDERLINE_MASK ? "on" : "off");
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
	unsigned long f = 0;
	f |= 1;
	f |= 12 << SIZE_SHIFT;
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
			f &= ~ID_MASK;
			f |= n & ID_MASK;
			break;
		case 's':
			printf("Enter font size (0-127): ");
			n = get_num();
			f &= ~SIZE_MASK;
			f |= n << SIZE_SHIFT & SIZE_MASK;
			break;
		case 'a':
			printf("Select alignment:\n");
			printf("l) left    c) center    r) right\n");
			c = get_char();
			if (c == 'l') {
				f &= ~ALIGNMENT_MASK;
				f |= 0 << ALIGNMENT_SHIFT & ALIGNMENT_MASK;
			} else if (c == 'c') {
				f &= ~ALIGNMENT_MASK;
				f |= 1 << ALIGNMENT_SHIFT & ALIGNMENT_MASK;
			} else if (c == 'r') {
				f &= ~ALIGNMENT_MASK;
				f |= 2 << ALIGNMENT_SHIFT & ALIGNMENT_MASK;
			} else
				printf("You should enter one of the letters: l, c, or r.\n");
			break;
		case 'b':
			f ^= BOLD_MASK;
			break;
		case 'i':
			f ^= ITALIC_MASK;
			break;
		case 'u':
			f ^= UNDERLINE_MASK;
			break;
		default:
			printf("Enter one of the letters: f, s, a, b, i, u, or q.\n");
		}
	}
	printf("Bye!\n");

	return 0;
}
