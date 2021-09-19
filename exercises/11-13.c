#include <stdio.h>

int main(int argc, char *argv[])
{
	for (int n = argc - 1; n > 0; n--)
		printf("%s ", argv[n]);
	return 0;
}
