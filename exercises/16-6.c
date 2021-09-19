#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM 7

struct names {
	char first[40];
	char last[40];
};

void showarray(const struct names ar[], size_t n)
{
	for (size_t i = 0; i < n; i++)
		printf("%zd: %s, %s\n", i + 1, ar[i].last, ar[i].first);
}

int comp_names(const void *p1, const void *p2)
{
	const struct names *n1 = (const struct names *)p1;
	const struct names *n2 = (const struct names *)p2;
	int r;

	r = strcmp(n1->last, n2->last);
	if (r == 0)
		return strcmp(n1->first, n2->first);
	else
		return r;
}

int main(void)
{
	struct names vals[NUM] = {{"Daniel", "Leach"},	    {"Claudia", "Townsend"},
				  {"Bertrand", "Townsend"}, {"Edward", "Ramos"},
				  {"Matthew", "Jones"},	    {"Sabrina", "Bartlett"},
				  {"Christina", "Pollard"}};

	puts("Random list:");
	showarray(vals, NUM);
	qsort(vals, NUM, sizeof(struct names), comp_names);
	puts("\nSorted list:");
	showarray(vals, NUM);

	return 0;
}
