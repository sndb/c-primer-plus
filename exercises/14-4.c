#include <stdio.h>

#define LEN 30

struct name {
	char first[LEN];
	char middle[LEN];
	char last[LEN];
};

struct person {
	int socsec;
	struct name name;
};

void pPersonAr(struct person ar[], size_t n);
void pPerson(struct person p);

int main(void)
{
	struct person persons[5] = {
		{302039823, {"Dribble", "McWell", "Flossie"}},
		{357082133, {"Donald", "", "Trump"}},
		{967334214, {"Mary", "", "Mason"}},
		{761575894, {"Melinda", "", "Rowland"}},
		{221889056, {"David", "", "Randall"}}
	};

	pPersonAr(persons, sizeof persons / sizeof *persons);

	return 0;
}

void pPersonAr(struct person ar[], size_t n)
{
	for (size_t i = 0; i < n; i++)
		pPerson(ar[i]);
}


void pPerson(struct person p)
{
	if (p.name.middle[0])
		printf("%s, %s %c. -- %d\n",
				p.name.first,
				p.name.last,
				p.name.middle[0],
				p.socsec);
	else
		printf("%s, %s -- %d\n",
				p.name.first,
				p.name.last,
				p.socsec);
}
