#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTITL 41
#define MAXAUTL 41
#define MAXBKS 5

enum menuchoice { MCQUIT, MCWQUIT, MCADD, MCMODIFY, MCDELETE, MCSHOW, MCNULL };

typedef struct {
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
	int todelete;
} book;

/* library actions */
size_t readlib(book lib[], size_t n, FILE *fp); // read library from fp to lib
void writelib(book lib[], size_t n, FILE *fp);	// write library from lib to fp
int printlib(book lib[], size_t n);		// print library
int printbook(book lib[], size_t i);		// print book
void addbook(book lib[], size_t i);		// add book to lib[i]
void modifybook(book lib[], size_t i);		// modify book lib[i]
void deletebook(book lib[], size_t i);		// delete book lib[i]

/* utility functions */
int getchoice(void);			// show menu and get choice
int isbookexist(book lib[], size_t i);	// check for existence
int getfreespace(book lib[], size_t n); // get unoccupied lib[i]
char *s_gets(char *st, int n);
void clearinput(void);

int main(void)
{
	book library[MAXBKS] = {0};
	FILE *pbooks = fopen("book.dat", "r+b");
	size_t filecount;
	int shouldquit = 0;

	if (!pbooks) {
		fprintf(stderr, "Can't open book.dat file\n");
		exit(1);
	}

	readlib(library, MAXBKS, pbooks);
	filecount = printlib(library, MAXBKS);
	printf("%zu books was read.\n", filecount);
	if (filecount == MAXBKS)
		fprintf(stderr, "The book.dat file is full.\nYou should delete some "
				"books before trying to add the new one.\n");

	while (!shouldquit) {
		int fs = getfreespace(library, MAXBKS);
		int i;

		switch (getchoice()) {
		case MCADD:
			if (fs >= 0) {
				printf("Using index %d\n", fs);
				addbook(library, fs);
				printlib(library, MAXBKS);
			} else
				printf("There is not enough space in the library.\n");
			break;
		case MCMODIFY:
			printf("Choose the book you want to modify: ");
			scanf("%d", &i);
			clearinput();
			modifybook(library, i);
			break;
		case MCDELETE:
			printf("Choose the book you want to delete: ");
			scanf("%d", &i);
			clearinput();
			deletebook(library, i);
			break;
		case MCSHOW:
			printlib(library, MAXBKS);
			break;
		case MCWQUIT:
			writelib(library, MAXBKS, pbooks);
			shouldquit = 1;
			break;
		case MCQUIT:
			shouldquit = 1;
			break;
		case MCNULL:
			fprintf(stderr, "You should enter the choice.\n");
			break;
		}
	}

	puts("Bye.");
	fclose(pbooks);

	return 0;
}

size_t readlib(book lib[], size_t n, FILE *fp)
{
	size_t c;
	for (c = 0; c < n && fread(&lib[c], sizeof(book), 1, fp) == 1; c++)
		if (!isbookexist(lib, c))
			break;
	return c;
}

void writelib(book lib[], size_t n, FILE *fp)
{
	book nil = {0};
	rewind(fp);
	for (size_t i = 0; i < n - 1; i++)
		fwrite(&lib[i], sizeof(book), 1, fp);
	fwrite(&nil, sizeof(book), 1, fp);
}

int printlib(book lib[], size_t n)
{
	int c = 0;

	for (size_t i = 0; i < n; i++) {
		if (i == 0)
			puts("Current contents of book.dat:");
		if (isbookexist(lib, i)) {
			printbook(lib, i);
			c++;
		} else {
			printf("Book %zu does not exist\n", i);
			break;
		}
	}
	if (!c)
		printf("You have no books.\n");

	return c;
}

int printbook(book lib[], size_t i)
{
	printf("%zu: %s by %s: $%.2f\n", i + 1, lib[i].title, lib[i].author, lib[i].value);
	return 1;
}

void addbook(book lib[], size_t i)
{
	book tmp;
	puts("Please add new book title.");
	puts("Press [enter] at the start of a line to cancel.");
	if (s_gets(tmp.title, MAXTITL) && tmp.title[0]) {
		puts("Now enter the author.");
		s_gets(tmp.author, MAXAUTL);
		puts("Now enter the value.");
		scanf("%f", &tmp.value);
	}
	clearinput();
	lib[i] = tmp;
	printbook(lib, i);
}

void modifybook(book lib[], size_t n)
{
	int c;

	printlib(lib, n);
	printf("Select book for modification: ");
	scanf("%d", &c);
	c--;

	clearinput();
	puts("Enter new book title:");
	s_gets(lib[c].title, MAXTITL);
	puts("Now enter the author.");
	s_gets(lib[c].author, MAXAUTL);
	puts("Now enter the value.");
	scanf("%f", &lib[c].value);

	clearinput();
	printlib(lib, n);
	printf("Book %d was modified.\n", c + 1);
}

void deletebook(book lib[], size_t n)
{
	int c;

	printlib(lib, n);
	printf("Select book for deletion: ");
	scanf("%d", &c);
	c--;

	lib[c].todelete = 1;

	clearinput();
	printlib(lib, n);
	printf("Book %d was deleted.\n", c + 1);
}

int getchoice(void)
{
	int ans;
	enum menuchoice c;

	printf("Enter your action:\n");
	printf("%-30s%30s\n", "[a]dd book", "[m]odify record");
	printf("%-30s%30s\n", "[d]elete book", "[s]how books");
	printf("%-30s%30s\n", "[w]rite and quit", "[q]uit without writing");

	ans = getchar();
	clearinput();
	switch (ans) {
	case 'a':
		c = MCADD;
		break;
	case 'm':
		c = MCMODIFY;
		break;
	case 'd':
		c = MCDELETE;
		break;
	case 's':
		c = MCSHOW;
		break;
	case 'w':
		c = MCWQUIT;
		break;
	case 'q':
		c = MCQUIT;
		break;
	default:
		c = MCNULL;
		break;
	}

	return c;
}

int isbookexist(book lib[], size_t i)
{
	printf("%d\n", !lib[i].todelete);
	printf("%d\n", lib[i].title[0]);
	if (!lib[i].todelete && lib[i].title[0]) {
		return 1;
	} else
		return 0;
}

int getfreespace(book lib[], size_t n)
{
	for (size_t i = 0; i < n; i++)
		if (!isbookexist(lib, i))
			return i;
	return -1;
}

char *s_gets(char *st, int n)
{
	char *ret_val;

	ret_val = fgets(st, n, stdin);
	if (ret_val) {
		st = strchr(st, '\n');
		if (st)
			*st = '\0';
		else
			clearinput();
	}

	return ret_val;
}

void clearinput(void)
{
	while (getchar() != '\n')
		continue;
}
