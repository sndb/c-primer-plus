#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 64

int main(int argc, char *argv[])
{
	char buf[BUFSIZE];
	size_t nbytes;

	if (argc != 3)
	{
		fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	FILE *fsrc = fopen(argv[1], "rb");
	FILE *fdst = fopen(argv[2], "wb");
	if (!fsrc || !fdst)
	{
		fprintf(stderr, "Can't open one of the files or both\n");
		exit(EXIT_FAILURE);
	}

	while ((nbytes = fread(buf, 1, BUFSIZE, fsrc)) > 0)
		fwrite(buf, 1, nbytes, fdst);

	fclose(fsrc);
	fclose(fdst);

	return 0;
}
