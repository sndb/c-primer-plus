#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define CLEARINPUT                                                                                 \
	while (getchar() != '\n')                                                                  \
	continue

#define LISTSIZE 10
#define BUFSIZE 256

char *get_first_word(char *word, const char *s)
{
	char *w = word;
	while (isspace(*s))
		s++;
	while (isalnum(*s)) {
		*w = *s;
		s++;
		w++;
	}
	*w = '\0';
	return word;
}

void print_list(char *list[], size_t n)
{
	for (size_t i = 0; i < n; i++)
		printf("%s", list[i]);
}

void sort_list_alpha(char *list[], size_t n)
{
	char *tmp;
	for (size_t i = 0; i < n - 1; i++)
		for (size_t j = i + 1; j < n; j++)
			if (list[i][0] > list[j][0]) {
				tmp = list[i];
				list[i] = list[j];
				list[j] = tmp;
			}
}

void sort_list_length(char *list[], size_t n)
{
	char *tmp;
	for (size_t i = 0; i < n - 1; i++)
		for (size_t j = i + 1; j < n; j++)
			if (strlen(list[i]) > strlen(list[j])) {
				tmp = list[i];
				list[i] = list[j];
				list[j] = tmp;
			}
}

void sort_list_first_word_length(char *list[], size_t n)
{
	char *tmp;
	char word_buf[2][BUFSIZE];
	for (size_t i = 0; i < n - 1; i++)
		for (size_t j = i + 1; j < n; j++)
			if (strlen(get_first_word(word_buf[0], list[i])) >
			    strlen(get_first_word(word_buf[1], list[j]))) {
				tmp = list[i];
				list[i] = list[j];
				list[j] = tmp;
			}
}

int main(void)
{
	char list[LISTSIZE][BUFSIZE];
	char *list_ptr[LISTSIZE];
	char *list_ptr_orig[LISTSIZE];
	size_t i;
	size_t j;
	int choice;

	printf("Enter up to 10 string:\n");
	for (i = 0; i < LISTSIZE && fgets(list[i], BUFSIZE, stdin); i++)
		;
	for (j = 0; j < i; j++) {
		list_ptr[j] = list[j];
		list_ptr_orig[j] = list[j];
	}

	while (1) {
		printf("Choose an action:\n"
		       "1) Print the original list of strings\n"
		       "2) Print the strings in ASCII collating sequence\n"
		       "3) Print the string in order of increasing length\n"
		       "4) Print the strings in order of the length of the first word\n"
		       "q) quit\n");
		if (scanf("%d", &choice) != 1)
			break;
		CLEARINPUT;
		if (choice < 1 || choice > 4) {
			printf("You should enter a number in the range of 1 to 4.\n");
			continue;
		}
		switch (choice) {
		case 1:
			print_list(list_ptr_orig, i);
			break;
		case 2:
			sort_list_alpha(list_ptr, i);
			print_list(list_ptr, i);
			break;
		case 3:
			sort_list_length(list_ptr, i);
			print_list(list_ptr, i);
			break;
		case 4:
			sort_list_first_word_length(list_ptr, i);
			print_list(list_ptr, i);
			break;
		}
	}
	printf("Bye!\n");

	return 0;
}
