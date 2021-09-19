/* films3.c -- using an ADT-style linked list */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "17-2-list.h"

void showmovies(Item item)
{
	printf("Movies: %s  Rating: %d\n", item.title, item.rating);
}

char *s_gets(char *st, int n)
{
	char *ret_val;
	char *find;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
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
	List movies;
	Item temp;

	/* initialize */
	InitializeList(&movies);
	if (ListIsFull(&movies))
	{
		fprintf(stderr, "No memory available! Bye!\n");
		exit(1);
	}

	/* gather and store */
	puts("Enter first movie title:");
	while (s_gets(temp.title, TSIZE) != NULL && temp.title[0] != '\0')
	{
		puts("Enter your rating <0-10>:");
		scanf("%d", &temp.rating);
		while (getchar() != '\n')
			continue;
		if (AddItem(temp, &movies) == false)
		{
			fprintf(stderr, "Problem allocating memory\n");
			break;
		}
		if (ListIsFull(&movies))
		{
			puts("The list is now full.");
			break;
		}
		puts("Enter next movie title (empty line to stop):");
	}

	/* display */
	if (ListIsEmpty(&movies))
		printf("No data entered. ");
	else
	{
		puts("Here is the movie list:");
		Traverse(&movies, showmovies);
	}
	printf("You entered %d movies.\n", ListItemCount(&movies));

	/* clean up */
	EmptyTheList(&movies);
	puts("Bye!");

	return 0;
}
