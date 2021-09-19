#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FNLEN 40
#define BUFSIZE 128

void clearinput(void)
{
	while (getchar() != '\n')
		continue;
}

char *s_fgets(char *s, int size, FILE *fp)
{
	char *r = fgets(s, size, fp);
	char *find;

	if (r) {
		find = strchr(r, '\n');
		if (*find == '\n')
			*find = '\0';
		else
			clearinput();
	}

	return r;
}

long reqpos(void)
{
	long pos;
	printf("Enter the position ('q' to exit): ");
	if (scanf("%ld", &pos) != 1)
		return -1;
	return pos;
}

int main(void)
{
	char filename[FNLEN];
	FILE *fp;
	long pos;

	printf("Enter the file name: ");
	s_fgets(filename, FNLEN, stdin);
	if (!(fp = fopen(filename, "r"))) {
		fprintf(stderr, "Could not open the file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while ((pos = reqpos()) >= 0) {
		char buf[BUFSIZE];
		fseek(fp, pos, SEEK_SET);
		fgets(buf, BUFSIZE, fp);
		fputs(buf, stdout);
	}
	fclose(fp);

	return 0;
}
