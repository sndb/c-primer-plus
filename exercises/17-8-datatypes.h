#ifndef DATATYPES_H_
#define DATATYPES_H_

#include <stdbool.h>

/* constants */
#define MAXTREESIZE 10
#define MAXLISTSIZE 5
#define SLEN 20

/* data structures */
typedef struct pet {
	char petname[SLEN];
	char petkind[SLEN];
} Pet;

typedef struct lnode {
	Pet pet;
	struct lnode *next;
} Lnode;

typedef struct list {
	Lnode *start;
	int size;
} List;

typedef List Item;

typedef struct trnode {
	Item item;
	struct trnode *left;
	struct trnode *right;
} Trnode;

typedef struct tree {
	Trnode *root;
	int size;
} Tree; /* no duplicate items are allowed in this tree */

/* list function prototypes */
void InitializeList(List *pl);                                 /* initialize a list to empty */
void DeleteList(List *pl);                                     /* delete everything from a list */

bool ListIsEmpty(const List *pl);                              /* determine if list is empty */
bool ListIsFull(const List *pl);                               /* determine if list is full */
int ListItemCount(const List *pl);                             /* determine number of items in list */

bool AddToList(Pet pet, List *pl);                             /* add an item to a list */
bool InList(Pet pet, const List *pl);                          /* find an item in a list */
bool DeleteFromList(Pet pet, List *pl);                        /* delete an item from a list */
void TraverseList(const List *pl, void (*pf)(Pet pet));        /* apply a function to each item in a list */

/* tree function prototypes */
void InitializeTree(Tree *pt);                                 /* initialize a tree to empty */
void DeleteTree(Tree *pt);                                     /* delete everything from a tree */

bool TreeIsEmpty(const Tree *pt);                              /* determine if tree is empty */
bool TreeIsFull(const Tree *pt);                               /* determine if tree is full */
int TreeItemCount(const Tree *pt);                             /* determine number of items in tree */
int TreeNodeCount(const Tree *pt);                             /* determine number of nodes in tree */

bool AddToTree(Pet pet, Tree *pt);                             /* add an item to a tree */
bool InTree(Pet pet, const Tree *pt);                          /* find an item in a tree */
List *GetListFromTree(Pet pet, const Tree *pt);                /* get list of pets with same name from a list */
bool DeleteFromTree(Pet pet, Tree *pt);                        /* delete an item from a tree */
void TraverseTree(const Tree *pt, void (*pf)(Pet pet));        /* apply a function to each item in a tree */

#endif
