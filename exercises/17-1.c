#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TSIZE 45

struct film {
	char title[TSIZE];
	int rating;
	struct film *next;
};

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

void display_list(const struct film *list)
{
	if (list != NULL)
	{
		printf("Movie: %s  Rating: %d\n", list->title, list->rating);
		display_list(list->next);
	}
}

void display_list_reverse(const struct film *list)
{
	if (list != NULL)
	{
		display_list_reverse(list->next);
		printf("Movie: %s  Rating: %d\n", list->title, list->rating);
	}
}

int main(void)
{
	struct film *head = NULL;
	struct film *prev, *current;
	char input[TSIZE];

	/* gather and store info */
	puts("Enter first movie title:");
	while (s_gets(input, TSIZE) != NULL && input[0] != '\0')
	{
		current = (struct film *)malloc(sizeof(struct film));
		if (head == NULL)
			head = current;
		else
			prev->next = current;
		current->next = NULL;
		strcpy(current->title, input);
		puts("Enter your rating <0-10>:");
		scanf("%d", &current->rating);
		while (getchar() != '\n')
			continue;
		puts("Enter next movie title (empty line to stop):");
		prev = current;
	}

	/* show list of movies */
	if (head == NULL)
		printf("No data entered. ");
	else
		printf("Here is the movie list:\n");
	puts("Original order:");
	display_list(head);
	puts("Reverse order:");
	display_list_reverse(head);

	/* free allocated memory */
	current = head;
	while (current != NULL)
	{
		free(current);
		current = current->next;
	}
	printf("Bye!\n");

	return 0;
}
