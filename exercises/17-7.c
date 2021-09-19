#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NDEBUG

#define MAXTREESIZE 4096
#define WORDSIZE 256

/* data types */
typedef struct occurrence {
	char word[WORDSIZE];
	unsigned int count;
} Occurrence;

typedef Occurrence Item;

typedef struct node {
	Item item;
	struct node *left;
	struct node *right;
} Node;

typedef struct tree {
	Node *root;
	unsigned int size;
} Tree;

typedef struct pair {
	Node *parent;
	Node *child;
} Pair;

/* util functions */
static inline void clear_input(void)
{
	while (getchar() != '\n')
		continue;
}

/* tree auxiliary functions */
Node *MakeNode(const char *word)
{
	Node *pnew;

#ifndef NDEBUG
	puts("Making new node");
#endif

	pnew = (Node *)malloc(sizeof(Node));
	if (pnew) {
		strcpy(pnew->item.word, word);
		pnew->item.count = 1;
		pnew->left = NULL;
		pnew->right = NULL;
	}

	return pnew;
}

bool ToLeft(const char *w1, const char *w2)
{
	if (strcmp(w1, w2) < 0)
		return true;
	else
		return false;
}

bool ToRight(const char *w1, const char *w2)
{
	if (strcmp(w1, w2) > 0)
		return true;
	else
		return false;
}

void AppendToNode(Node *root, Node *pnode)
{
#ifndef NDEBUG
	puts("Appending node to root");
#endif

	if (ToLeft(pnode->item.word, root->item.word)) {
		if (!root->left)
			root->left = pnode;
		else
			AppendToNode(root->left, pnode);
	} else if (ToRight(pnode->item.word, root->item.word)) {
		if (!root->right)
			root->right = pnode;
		else
			AppendToNode(root->right, pnode);
	} else {
		fprintf(stderr, "Location error in AppendToNode()\n");
		exit(EXIT_FAILURE);
	}

#ifndef NDEBUG
	puts("Node is appended");
#endif
}

Pair FindWord(const Tree *ptree, const char *word)
{
	Pair p;
	p.parent = NULL;
	p.child = ptree->root;

	if (!p.child)
		return p;

	while (p.child) {
		if (ToLeft(word, p.child->item.word)) {
			p.parent = p.child;
			p.child = p.parent->left;
		} else if (ToRight(word, p.child->item.word)) {
			p.parent = p.child;
			p.child = p.parent->right;
		} else
			break;
	}

	return p;
}

void InOrder(Node *pnode, void (*pfunc)(Item *item))
{
	if (pnode) {
		InOrder(pnode->left, pfunc);
		pfunc(&pnode->item);
		InOrder(pnode->right, pfunc);
	}
}

void DeleteAllNodes(Node *pnode)
{
	Node *pright;

	if (pnode) {
		pright = pnode->right;
		DeleteAllNodes(pnode->left);
		free(pnode);
		DeleteAllNodes(pright);
	}
}

/* tree interface functions */
void InitializeTree(Tree *ptree)
{
#ifndef NDEBUG
	puts("Initializing tree");
#endif

	ptree->root = NULL;
	ptree->size = 0;
}

bool TreeIsEmpty(const Tree *ptree) { return ptree->size == 0; }

bool TreeIsFull(const Tree *ptree)
{
	Node *pn;
	bool r;

	if (ptree->size >= MAXTREESIZE)
		return true;

	pn = (Node *)malloc(sizeof(Node));
	if (!pn)
		r = true;
	else
		r = false;
	free(pn);

	return r;
}

unsigned int TreeSize(const Tree *ptree) { return ptree->size; }

bool AddToTree(Tree *ptree, const char *word)
{
	Node *pnew;

#ifndef NDEBUG
	printf("Trying to add '%s' to tree\n", word);
#endif

	if (TreeIsFull(ptree)) {
		fprintf(stderr, "Tree is full\n");
		return false;
	}
	pnew = MakeNode(word);
	if (!pnew) {
		fprintf(stderr, "Can't create node\n");
		return false;
	}
	if (!ptree->root)
		ptree->root = pnew;
	else
		AppendToNode(ptree->root, pnew);

	return true;
}

Node *FindInTree(const Tree *ptree, const char *word)
{
	Pair p;

#ifndef NDEBUG
	printf("Trying to find '%s'\n", word);
#endif

	p = FindWord(ptree, word);
	if (p.child)
		return p.child;

	return NULL;
}

void TraverseTree(Tree *ptree, void (*pfunc)(Item *pitem)) { InOrder(ptree->root, pfunc); }

void DeleteTree(Tree *ptree)
{
#ifndef NDEBUG
	puts("Deleting tree");
#endif

	if (ptree)
		DeleteAllNodes(ptree->root);
	ptree->root = NULL;
	ptree->size = 0;
}

/* program specific functions */
void print_occurrences(Item *pitem) { printf("%20s: %u\n", pitem->word, pitem->count); }

int get_word(FILE *stream, char *word)
{
	char wbuf[WORDSIZE];
	char *wscan = wbuf;
	int r;

#ifndef NDEBUG
	puts("Getting a word");
#endif

	r = fscanf(stream, "%s", wbuf);
	while (*wscan) {
		if (!isalpha(*wscan))
			break;
		*word = *wscan;
		wscan++;
		word++;
	}
	*word = '\0';

	return r;
}

void show_menu(void)
{
	printf("[l] List all the words along with the number of occurrences\n"
	       "[s] Search for a word\n"
	       "[q] Quit\n");
}

int main(int argc, char *argv[])
{
	FILE *fp;
	Tree tree;
	Node *node;
	char word[WORDSIZE];
	char ch;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <FILE>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (!fp) {
		fprintf(stderr, "File %s couldn't be opened\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	InitializeTree(&tree);
	while (get_word(fp, word) == 1) {
		if (*word) {
			if ((node = FindInTree(&tree, word)))
				node->item.count++;
			else
				AddToTree(&tree, word);
		}
	}
	fclose(fp);

	while (1) {
		show_menu();
		scanf("%c", &ch);
		clear_input();
		if (ch == 'q')
			break;
		switch (ch) {
		case 'l':
			TraverseTree(&tree, print_occurrences);
			break;
		case 's':
			puts("Enter a word:");
			scanf("%s", word);
			clear_input();
			if ((node = FindInTree(&tree, word)))
				printf("%s: %u\n", node->item.word, node->item.count);
			else
				puts("Not found");
			break;
		default:
			puts("You should enter l, s, or q:");
		}
		putchar('\n');
	}
	DeleteTree(&tree);

	return 0;
}
