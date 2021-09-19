#include <stdio.h>
#include <float.h>

int main(void)
{
	double dbl = 1.0/3.0;
	float flt = 1.0/3.0;

	printf("DBL_DIG is %d.\n", DBL_DIG);
	printf("%.4f\n", dbl);
	printf("%.12f\n", dbl);
	printf("%.16f\n\n", dbl);

	printf("FLT_DIG is %d.\n", FLT_DIG);
	printf("%.4f\n", flt);
	printf("%.12f\n", flt);
	printf("%.16f\n", flt);

	return 0;
}
