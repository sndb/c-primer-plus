#include <stdio.h>

struct month {
	char name[20];
	char abbr[3];
	int ndays;
	int mnum;
};

int howmanydays(int mnum);

const struct month year[12] = {
	{ "January",   "Jan", 31, 1  },
	{ "February",  "Feb", 28, 2  },
	{ "March",     "Mar", 31, 3  },
	{ "April",     "Apr", 30, 4  },
	{ "May",       "May", 31, 5  },
	{ "June",      "Jun", 30, 6  },
	{ "Jule",      "Jul", 31, 7  },
	{ "August",    "Aug", 31, 8  },
	{ "September", "Sep", 30, 9  },
	{ "October",   "Oct", 31, 10 },
	{ "November",  "Nov", 30, 11 },
	{ "December",  "Dec", 31, 12 }
};

int main(void)
{
	struct month may = year[0];

	printf("There is %d days from the New Year to %s.\n",
			howmanydays(may.mnum), may.name);

	return 0;
}

int howmanydays(int mnum)
{
	int days = 0;
	for (int i = 0; i < mnum; i++)
		days += year[i].ndays;
	return days;
}
