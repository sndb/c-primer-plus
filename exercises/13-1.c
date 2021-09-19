#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 256

int main(void)
{
	int ch;
	FILE *fp;
	char filename[LEN];
	char *c;
	unsigned long count = 0;

	printf("Enter the filename: ");
	if (fgets(filename, LEN, stdin))
	{
		c = strchr(filename, '\n');
		if (c)
			*c = '\0';
	}
	if ((fp = fopen(filename, "r")) == NULL)
	{
		printf("Can't open %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while ((ch = getc(fp)) != EOF)
	{
		putc(ch, stdout);
		count++;
	}
	fclose(fp);
	printf("File %s has %lu characters\n", filename, count);

	return 0;
}
