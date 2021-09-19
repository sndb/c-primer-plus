#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "s_gets.h"

#define ANSWER "grant"
#define SIZE 40

char * stolower(char * s)
{
	char * c = s;

	while (*c != '\0')
	{
		*c = tolower(*c);
		c++;
	}
	return s;
}

int main(void)
{
	char try[SIZE];

	puts("Who is buried in Grant's tomb?");
	s_gets(try, SIZE);
	while (strcmp(stolower(try), ANSWER) != 0)
	{
		puts("No, that's wrong. Try again.");
		s_gets(try, SIZE);
	}
	puts("That's right!");

	return 0;
}
