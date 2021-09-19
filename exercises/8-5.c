#include <stdio.h>

int main(void)
{
	int upper = 101;
	int lower = 1;
	int guess = (upper + lower) / 2 - 1;
	char response;

	printf("pick an integer from %d to %d. i will try to guess it.\n\n", lower, upper - 1);
	printf("respond with a 'y' if my guess is right and with '<' or '>' if \n"
	       "your number is less than or greater than my guess.\n\n");
	printf("uh...is your number %d?\n", guess);
	while ((response = getchar()) != 'y') {
		if (response == '>')
			lower = guess;
		else if (response == '<')
			upper = guess;
		else
			printf("sorry, i understand only y or n.\n");
		guess = (upper + lower) / 2;
		printf("well, then, is it %d?\n", guess);
		while (getchar() != '\n')
			continue;
	}
	printf("i knew i could do it!\n");

	return 0;
}
