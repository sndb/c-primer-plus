/* petclub.c -- use a binary search tree */
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "17-8-datatypes.h"

char menu(void);
void addpet(Tree *pt);
void showpets(const Tree *pt);
void printitem(Pet pet);
void findpet(const Tree *pt);
void droppet(Tree *pt);
void uppercase(char *str);
char *s_gets(char *st, int n);

char menu(void)
{
	int ch;

	puts("Nerfville Pet Club Membership Program");
	puts("Enter the letter corresponding to your choice:");
	puts("a) add a pet         l) show list of pets");
	puts("n) number of pets    f) find pets");
	puts("d) delete a pet      q) quit");
	while ((ch = getchar()) != EOF) {
		while (getchar() != '\n')
			continue;
		ch = tolower(ch);
		if (!strchr("alfndq", ch))
			puts("Please enter an a, l, f, n, d, or q:");
		else
			break;
	}
	if (ch == EOF)
		ch = 'q';

	return ch;
}

void addpet(Tree *pt)
{
	Pet pet;

	if (TreeIsFull(pt))
		puts("No room in the club!");
	else {
		puts("Please enter name of pet:");
		s_gets(pet.petname, SLEN);
		puts("Please enter pet kind");
		s_gets(pet.petkind, SLEN);
		uppercase(pet.petname);
		uppercase(pet.petkind);
		AddToTree(pet, pt);
	}
}

void showpets(const Tree *pt)
{
	if (TreeIsEmpty(pt))
		puts("No entries!");
	else
		TraverseTree(pt, printitem);
}

void printitem(Pet pet) { printf("Pet: %-19s  Kind: %-19s\n", pet.petname, pet.petkind); }

void findpet(const Tree *pt)
{
	Pet pet;
	List *pl;

	if (TreeIsEmpty(pt)) {
		puts("No entries!");
		return;
	}

	puts("Please enter name of pet you wish to find:");
	s_gets(pet.petname, SLEN);
	uppercase(pet.petname);
	pl = GetListFromTree(pet, pt);
	TraverseList(pl, printitem);
}

void droppet(Tree *pt)
{
	Pet pet;

	if (TreeIsEmpty(pt)) {
		puts("No entries!");
		return;
	}

	puts("Please enter name of pet you wish to delete:");
	s_gets(pet.petname, SLEN);
	puts("Please enter pet kind:");
	s_gets(pet.petkind, SLEN);
	uppercase(pet.petname);
	uppercase(pet.petkind);
	printf("%s the %s ", pet.petname, pet.petkind);
	if (DeleteFromTree(pet, pt))
		printf("is dropped from the club.\n");
	else
		printf("is not a member.\n");
}

void uppercase(char *str)
{
	while (*str) {
		*str = toupper(*str);
		str++;
	}
}

char *s_gets(char *st, int n)
{
	char *ret_val;
	char *find;

	ret_val = fgets(st, n, stdin);
	if (ret_val) {
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}

int main(void)
{
	Tree pets;
	char choice;

	InitializeTree(&pets);
	while ((choice = menu()) != 'q') {
		switch (choice) {
		case 'a':
			addpet(&pets);
			break;
		case 'l':
			showpets(&pets);
			break;
		case 'f':
			findpet(&pets);
			break;
		case 'n':
			printf("%d pets in club\n", TreeNodeCount(&pets));
			break;
		case 'd':
			droppet(&pets);
			break;
		default:
			puts("Switching error");
		}
	}
	DeleteTree(&pets);
	puts("Bye.");

	return 0;
}
