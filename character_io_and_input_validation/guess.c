#include <stdio.h>

int main(void)
{
	int guess = 1;
	char response;

	printf("pick an integer from 1 to 100. i will try to guess it.\n");
	printf("respond with a 'y' if my guess is right and with an 'n' if it is wrong.\n");
	printf("uh...is your number %d?\n", guess);
	while ((response = getchar()) != 'y')
	{
		if (response == 'n')
			printf("well, then, is it %d?\n", ++guess);
		else
			printf("sorry, i understand only y or n.\n");
		while (getchar() != '\n')
			continue;
	}
	printf("i knew i could do it!\n");

	return 0;
}
