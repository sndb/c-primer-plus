#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	unsigned long chcount[argc];
	for (int i = 0; i < argc; i++)
		chcount[i] = 0;

	if (argc < 2) {
		fprintf(stderr, "Usage: %s <CHARACTER> [FILE...]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if (strlen(argv[1]) > 1) {
		fprintf(stderr, "Usage: %s <CHARACTER> [FILE...]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if (argc == 2) {
		while (!feof(stdin)) {
			int ch = getc(stdin);
			if (ch == *argv[1])
				chcount[0]++;
		}
		printf("stdin has %lu %c's\n", chcount[0], *argv[1]);
	} else
		for (int i = 2; i < argc; i++) {
			fp = fopen(argv[i], "r");
			if (!fp) {
				fprintf(stderr, "File %s can't be opened\n", argv[i]);
				continue;
			}
			while (!feof(fp)) {
				int ch = getc(fp);
				if (ch == *argv[1])
					chcount[i]++;
			}
			printf("File %s has %lu %c's\n", argv[i], chcount[i], *argv[1]);
			fclose(fp);
		}
	return 0;
}
