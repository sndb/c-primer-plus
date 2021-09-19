// same as 14-8

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SEATNUM 12

enum choice { A, B, C, D, E, F };
const char *choices = "abcdef";

struct seat {
	int id;
	int assigned;
	char lastname[41];
	char firstname[41];
};

void clearinput(void)
{
	while (getchar() != '\n')
		continue;
}

char *sget(char *s, int size)
{
	char *r = fgets(s, size, stdin);
	char *find;

	if (r) {
		find = strchr(r, '\n');
		if (*find == '\n')
			*find = '\0';
		else
			clearinput();
	}

	return r;
}

char getMenuChoice(void)
{
	char c;

	printf("To choose a function, enter its letter label:\n"
	       "a) Show number of empty seats\n"
	       "b) Show list of empty seats\n"
	       "c) Show alphabetical list of seats\n"
	       "d) Assign a customer to a seat assignment\n"
	       "e) Delete a seat assignment\n"
	       "f) Quit\n");
	c = getchar();
	clearinput();

	return c;
}

enum choice getFuncChoice(void)
{
	char c = getMenuChoice();
	char *cp;

	while (!(cp = strchr(choices, c)))
		c = getMenuChoice();
	return cp - choices;
}

void showNumEmptySeats(struct seat seats[], size_t n)
{
	int c = 0;
	for (size_t i = 0; i < n; i++) {
		if (!seats[i].assigned)
			c++;
	}
	printf("Number of empty seats: %d\n", c);
}

void showListEmptySeats(struct seat seats[], size_t n)
{
	for (size_t i = 0; i < n; i++) {
		if (!seats[i].assigned)
			printf("ID: %d, unassigned\n", seats[i].id);
	}
}

void showAlphaListSeats(struct seat seats[], size_t n)
{
	struct seat **tmp = (struct seat **)malloc(sizeof(struct seat *) * n);
	struct seat *x;
	if (!tmp)
		exit(2);

	for (size_t i = 0; i < n; i++)
		tmp[i] = &seats[i];
	for (size_t i = 0; i < n - 1; i++)
		for (size_t j = i + 1; j < n; j++)
			if (strcmp(tmp[i]->lastname, tmp[j]->lastname) > 0) {
				x = tmp[i];
				tmp[i] = tmp[j];
				tmp[j] = x;
			}
	for (size_t i = 0; i < n; i++)
		if (tmp[i]->assigned)
			printf("ID: %d, %s, %s\n", tmp[i]->id, tmp[i]->lastname, tmp[i]->firstname);

	free(tmp);
}

void assignCustomer(struct seat seats[], size_t n)
{
	struct seat tmp = {.assigned = 1};
	printf("Enter seat ID, customer's lastname and firstname\n");
	if (scanf("%d %s %s", &tmp.id, tmp.lastname, tmp.firstname) == 3 && tmp.id > 0 &&
	    (size_t)tmp.id <= n && !seats[tmp.id - 1].assigned)
		seats[tmp.id - 1] = tmp;
	else
		fprintf(stderr, "An error has occured on assigning the customer.\n");
	clearinput();
}

void deleteCustomer(struct seat seats[], size_t n)
{
	struct seat tmp = {0};
	printf("Enter customer ID for deletion: ");
	if (scanf("%d", &tmp.id) == 1 && tmp.id > 0 && (size_t)tmp.id <= n &&
	    seats[tmp.id - 1].assigned)
		seats[tmp.id - 1] = tmp;
	clearinput();
}

void quit(struct seat seats[], size_t n)
{
	showAlphaListSeats(seats, n);
	printf("Thank you for your confidence in the Colossus Airlines!\n");
}

int main(void)
{
	struct seat seats[SEATNUM] = {0};
	enum choice i;
	void (*seatfuncs[])(struct seat *, size_t) = {showNumEmptySeats,  showListEmptySeats,
						      showAlphaListSeats, assignCustomer,
						      deleteCustomer,	  quit};
	FILE *datafile = fopen("seats.dat", "r+b");

	if (!datafile) {
		printf("Creating and initializing datafile...\n");
		for (size_t i = 0; i < SEATNUM; i++)
			seats[i].id = i + 1;
		datafile = fopen("seats.dat", "w+b");
		if (fwrite(seats, sizeof(struct seat), SEATNUM, datafile) != SEATNUM) {
			fprintf(stderr, "Could not write data to datafile\n");
			exit(4);
		}
		rewind(datafile);
	}

	if (fread(seats, sizeof(struct seat), SEATNUM, datafile) != SEATNUM) {
		fprintf(stderr, "Could not read data from datafile\n");
		exit(3);
	}
	rewind(datafile);

	while ((i = getFuncChoice()) != F) {
		seatfuncs[i](seats, SEATNUM);
	}

	if (fwrite(seats, sizeof(struct seat), SEATNUM, datafile) != SEATNUM) {
		fprintf(stderr, "Could not write data to datafile\n");
		exit(4);
	}

	fclose(datafile);

	return 0;
}
