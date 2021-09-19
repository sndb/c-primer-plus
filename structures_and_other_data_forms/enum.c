#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define LEN 30

enum spectrum {red, orange, yellow, green, blue, violet};
const char *colors[] = {"red", "orange", "yellow", "green", "blue", "violet"};

char *s_gets(char *st, int n)
{
	char *ret_val;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		st = strchr(st, '\n');
		if (st)
			*st = '\0';
		else
			while (getchar() != '\n')
				continue;
	}

	return ret_val;
}

int main(void)
{
	char choice[LEN];
	enum spectrum color;
	bool color_is_found = false;

	puts("Enter a color (empty line to quit):");
	while (s_gets(choice, LEN) && choice[0])
	{
		for (color = red; color <= violet; color++)
		{
			if (strcmp(choice, colors[color]) == 0)
			{
				color_is_found = true;
				break;
			}
		}
		if (color_is_found)
			switch(color)
			{
				case red:
					puts("Roses are red.");
					break;
				case orange:
					puts("Poppies are orange.");
					break;
				case yellow:
					puts("Sunflowers are yellow.");
					break;
				case green:
					puts("Grass is green.");
					break;
				case blue:
					puts("Bluebells are blue.");
					break;
				case violet:
					puts("Violets are violet.");
					break;
			}
		else
			printf("I don't know about the color %s.\n", choice);
		color_is_found = false;
		puts("Next color, please (empty line to quit):");
	}
	puts("Goodbye!");

	return 0;
}
