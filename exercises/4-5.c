#include <stdio.h>
#include <limits.h>

int main(void)
{
	const int bits_in_byte = CHAR_BIT;

	float dl_spd_mbs;
	float fsize_mb;
	float dl_time;

	printf("Enter download speed in megabits per second: ");
	scanf("%f", &dl_spd_mbs);
	printf("Enter size of a file in megabytes (MB): ");
	scanf("%f", &fsize_mb);
	dl_time = fsize_mb * bits_in_byte / dl_spd_mbs;
	printf("At %.2f megabits per second, a file of %.2f megabytes\n"
			"downloads in %.2f seconds.\n", dl_spd_mbs, fsize_mb, dl_time);

	return 0;
}
