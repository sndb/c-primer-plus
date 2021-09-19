#include <stdio.h>
#include <float.h>
#include <limits.h>

int main(void)
{
	int i_max, i_overflow;
	float f_max, f_min;
	float f_overflow, f_underflow;

	printf("INT_MAX = %d\n", INT_MAX);
	printf("FLT_MAX = %e\n", FLT_MAX);
	printf("DBL_MAX = %e\n", DBL_MAX);
	printf("LDBL_MAX = %Le\n\n", LDBL_MAX);

	printf("INT_MIN = %d\n", INT_MIN);
	printf("FLT_MIN = %e\n", FLT_MIN);
	printf("DBL_MIN = %e\n", DBL_MIN);
	printf("LDBL_MIN = %Le\n\n", LDBL_MIN);

	printf("FLT_DIG = %d\n", FLT_DIG);
	printf("DBL_DIG = %d\n", DBL_DIG);
	printf("LDBL_DIG = %d\n\n", LDBL_DIG);

	printf("FLT_MIN_10_EXP = %d\n", FLT_MIN_10_EXP);
	printf("DBL_MIN_10_EXP = %d\n", DBL_MIN_10_EXP);
	printf("LDBL_MIN_10_EXP = %d\n\n", LDBL_MIN_10_EXP);

	printf("FLT_MAX_10_EXP = %d\n", FLT_MAX_10_EXP);
	printf("DBL_MAX_10_EXP = %d\n", DBL_MAX_10_EXP);
	printf("LDBL_MAX_10_EXP = %d\n\n", LDBL_MAX_10_EXP);

	printf("Size of \'int\' in bits: %zd\n\n", sizeof(int) * 8);

	i_max = INT_MAX;
	i_overflow = i_max + 1;

	printf("%d %d\n", i_max, i_overflow);

	f_max = FLT_MAX;
	f_overflow = f_max * 2.;

	printf("%e %e\n", f_max, f_overflow);

	f_min = FLT_MIN;
	f_underflow = f_min / 2.;

	printf("%e %e\n", f_min, f_underflow);

	return 0;
}
