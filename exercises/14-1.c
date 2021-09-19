#include <stdio.h>
#include <string.h>

struct month {
	char name[20];
	char abbr[3];
	int ndays;
	int mnum;
};

int howmanydays(char *month);

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
	char *month = "February";

	printf("There is %d days from the New Year to %s.\n",
			howmanydays(month), month);

	return 0;
}

int howmanydays(char *month)
{
	int days = 0;
	int found = 0;

	for (size_t i = 0; i < sizeof year; i++)
	{
		days += year[i].ndays;
		if (strcmp(year[i].name, month) == 0)
		{
			found = 1;
			break;
		}
	}
	if (!found)
		return -1;

	return days;
}
