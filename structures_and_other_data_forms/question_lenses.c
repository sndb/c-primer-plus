#include <stdio.h>
#include <string.h>

typedef struct lens {
	float foclen;
	float fstop;
	char brand[30];
} LENS;

void showlensinfo(LENS lens)
{
	printf("brand: %s, aperture: %g, focal length: %g\n",
			lens.brand, lens.fstop, lens.foclen);
}

int main(void)
{
	LENS lenses[10] = {[2] = {.brand = "Remarkatar", .foclen = 500.0, .fstop = 2.0} };

	strcpy(lenses[3].brand, "Remarkatar");
	lenses[3].foclen = 500.0;
	lenses[3].fstop = 2.0;

	showlensinfo(lenses[2]);
	showlensinfo(lenses[3]);

	return 0;
}
