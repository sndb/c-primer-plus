#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSTRLEN 41
#define MAXNUMLEN 10

int main(void)
{
	FILE *fp;
	char words[MAXNUMLEN + MAXSTRLEN + 1];
	int nmax = 0;
	int n;

	if (!(fp = fopen("wordy", "a+"))) {
		fprintf(stdout, "Can't open \"wordy\" file\n");
		exit(EXIT_FAILURE);
	}

	rewind(fp);
	while (fscanf(fp, "%d %*s", &n) == 1)
		if (n > nmax)
			nmax = n;

	puts("Enter words to add to the file;"
	     " press # key at the beginning of a line to terminate.");
	while ((fscanf(stdin, "%40s", words) == 1) & (words[0] != '#')) {
		nmax++;
		fprintf(fp, "%d %s\n", nmax, words);
	}

	puts("File contents:");
	rewind(fp);
	while (fscanf(fp, "%d %s", &n, words) == 2)
		printf("%d %s\n", n, words);

	puts("Done");
	if (fclose(fp) != 0)
		fprintf(stderr, "Error closing file\n");

	return 0;
}
