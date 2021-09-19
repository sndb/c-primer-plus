#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int static_store = 30;
const char * pcg = "string literal";

int main(void)
{
	int auto_store = 40;
	char auto_string[] = "auto char array";
	int * pi;
	char * pcl;

	pi = (int *) malloc(sizeof(int));
	*pi = 35;

	pcl = (char *) malloc(strlen("dynamic string") + 1);
	strcpy(pcl, "dynamic string");

	printf("%16s: %d at %p\n", "static store", static_store, &static_store);
	printf("%16s: %d at %p\n", "auto store", auto_store, &auto_store);
	printf("%16s: %d at %p\n", "*pi", *pi, pi);
	printf("%20s at %p\n", pcg, pcg);
	printf("%20s at %p\n", auto_string, auto_string);
	printf("%20s at %p\n", pcl, pcl);
	printf("%20s at %p\n", "quoted string", "quoted string");

	free(pi);
	free(pcl);

	return 0;
}
