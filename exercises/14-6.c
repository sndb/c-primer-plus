#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 31
#define MAXNUM 19

struct player {
	int num; // 0 - 18
	char first[LEN];
	char last[LEN];
	int bats;
	int hits;
	int walks;
	int rbi;
	float baverage;
};

void calcbaverage(struct player *p) { p->baverage = (float)p->hits / p->bats; }

void showplayer(struct player *p)
{
	printf("%d: %s %s, bats: %d, hits: %d, walks: %d, RBI: %d. Batting "
	       "average: %.2f.\n",
	       p->num, p->first, p->last, p->bats, p->hits, p->walks, p->rbi,
	       p->baverage);
}

void showteam(struct player *t)
{
	calcbaverage(t);
	printf("Combined statistics: bats: %d, hits: %d, walks: %d, RBI: %d. "
	       "Batting average: %.2f.\n",
	       t->bats, t->hits, t->walks, t->rbi, t->baverage);
}

int main(void)
{
	FILE *data = fopen("softball.dat", "r");
	struct player players[MAXNUM] = {0};
	struct player tmp = {0};
	struct player combined = {0};

	while (fscanf(data, "%d %s %s %d %d %d %d", &tmp.num, tmp.first,
		      tmp.last, &tmp.bats, &tmp.hits, &tmp.walks,
		      &tmp.rbi) == 7) {
		int i = tmp.num;
		if (!*players[i].first) {
			players[i].num = tmp.num;
			strncpy(players[i].first, tmp.first, LEN);
			strncpy(players[i].last, tmp.last, LEN);
		}
		players[i].bats += tmp.bats;
		players[i].hits += tmp.hits;
		players[i].walks += tmp.walks;
		players[i].rbi += tmp.rbi;
	}
	for (size_t i = 0; i < MAXNUM; i++) {
		if (players[i].bats != 0) {
			calcbaverage(&players[i]);
		}
		if (*players[i].first) {
			showplayer(&players[i]);
			combined.bats += players[i].bats;
			combined.hits += players[i].hits;
			combined.walks += players[i].walks;
			combined.rbi += players[i].rbi;
		}
	}
	showteam(&combined);

	return 0;
}
