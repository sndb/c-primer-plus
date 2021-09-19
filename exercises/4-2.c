#include <stdio.h>
#include <string.h>

int main(void)
{
	char name[50];
	int name_length;

	printf("Enter your name: ");
	scanf("%s", name);
	name_length = strlen(name);
	printf("a: \"%s\"\n", name);
	printf("b: \"%20s\"\n", name);
	printf("c: \"%-20s\"\n", name);
	printf("d: \"%*s\"\n", name_length + 3, name);

	return 0;
}
