#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "17-8-datatypes.h"

/* SeekItem function's return data type */
typedef struct pair {
	Trnode *parent;
	Trnode *child;
} Pair;

/* prototypes for local list functions */
static Lnode *MakeListNode(Pet pet);
static Lnode *LastListNode(const Lnode *pn);
static void DeleteAllListNodes(Lnode *pn);

/* prototypes for local tree functions */
static Trnode *MakeTreeNode(Pet pet);
static bool ToLeft(Pet p1, Pet p2);
static bool ToRight(Pet p1, Pet p2);
static void AddTreeNode(Trnode *new_node, Trnode *root);
static void InOrder(const Trnode *root, void (*pf)(Pet pet));
static Pair SeekItem(Pet pet, const Tree *ptree);
static void DeleteTreeNode(Trnode **ptr);
static void DeleteAllTreeNodes(Trnode *ptr);
static int CountAllNodes(const Trnode *pn);

/* list function definitions */
void InitializeList(List *pl)
{
	pl->start = NULL;
	pl->size = 0;
}

void DeleteList(List *pl)
{
	if (pl) {
		DeleteAllListNodes(pl->start);
		pl->start = NULL;
		pl->size = 0;
	}
}

bool ListIsEmpty(const List *pl) { return pl->size == 0; }

bool ListIsFull(const List *pl)
{
	Pet p = {"petname", "petkind"};
	Lnode *new_node;
	bool status;

	if (pl->size == MAXLISTSIZE)
		return true;

	new_node = MakeListNode(p);
	if (!new_node)
		status = true;
	else
		status = false;
	free(new_node);

	return status;
}

int ListItemCount(const List *pl) { return pl->size; }

bool AddToList(Pet pet, List *pl)
{
	Lnode *new_node = MakeListNode(pet);

	if (!new_node)
		return false;

	if (InList(pet, pl)) {
		fprintf(stderr, "A pet with the same name and kind is already in the list\n");
		free(new_node);
		return false;
	}
	if (!pl->start)
		pl->start = new_node;
	else
		LastListNode(pl->start)->next = new_node;
	pl->size++;

	return true;
}

bool InList(Pet pet, const List *pl)
{
	Lnode *pn = pl->start;

	while (pn) {
		if (!strcmp(pn->pet.petkind, pet.petkind) && !strcmp(pn->pet.petname, pet.petname))
			return true;
		pn = pn->next;
	}

	return false;
}

bool DeleteFromList(Pet pet, List *pl)
{
	Lnode *pn = pl->start;
	Lnode *pnprev = NULL;

	while (pn) {
		if (!strcmp(pn->pet.petkind, pet.petkind) &&
		    !strcmp(pn->pet.petname, pet.petname)) {
			if (!pnprev)
				pl->start = pn->next;
			else
				pnprev->next = pn->next;
			free(pn);
			pl->size--;
			return true;
		}
		pnprev = pn;
		pn = pn->next;
	}

	return false;
}

void TraverseList(const List *pl, void (*pf)(Pet pet))
{
	Lnode *pn = pl->start;

	while (pn) {
		pf(pn->pet);
		pn = pn->next;
	}
}

/* tree function definitions */
void InitializeTree(Tree *pt)
{
	pt->root = NULL;
	pt->size = 0;
}

void DeleteTree(Tree *pt)
{
	if (pt) {
		DeleteAllTreeNodes(pt->root);
		pt->root = NULL;
		pt->size = 0;
	}
}

bool TreeIsEmpty(const Tree *pt) { return !pt->root; }

bool TreeIsFull(const Tree *pt) { return pt->size == MAXTREESIZE; }

int TreeItemCount(const Tree *pt) { return pt->size; }

int TreeNodeCount(const Tree *pt) { return CountAllNodes(pt->root); }

bool AddToTree(Pet pet, Tree *pt)
{
	Trnode *new_node;
	Trnode *find = SeekItem(pet, pt).child;

	if (TreeIsFull(pt)) {
		fprintf(stderr, "Tree is full\n");
		return false;
	}

	if (find) {
		return AddToList(pet, &find->item);
	}

	new_node = MakeTreeNode(pet);
	if (!new_node) {
		fprintf(stderr, "Couldn't create node\n");
		return false;
	}
	/* succeeded in creating a new tree node */
	pt->size++;

	if (!pt->root)
		/* tree is empty, new node is tree root */
		pt->root = new_node;
	else
		/* tree is not empty, add node to tree */
		AddTreeNode(new_node, pt->root);

	return true;
}

bool InTree(Pet pet, const Tree *pt) { return (!SeekItem(pet, pt).child) ? false : true; }

List *GetListFromTree(Pet pet, const Tree *pt)
{
	Trnode *pn = SeekItem(pet, pt).child;
	if (!pn)
		return NULL;

	return &pn->item;
}

bool DeleteFromTree(Pet pet, Tree *pt)
{
	Pair look;

	look = SeekItem(pet, pt);
	if (!look.child)
		return false;

	if (ListItemCount(&look.child->item) > 1) {
		DeleteFromList(pet, &look.child->item);
		return true;
	}

	if (!look.parent)
		DeleteTreeNode(&pt->root);
	else if (look.parent->left == look.child)
		DeleteTreeNode(&look.parent->left);
	else
		DeleteTreeNode(&look.parent->right);
	pt->size--;

	return true;
}

void TraverseTree(const Tree *ptree, void (*pf)(Pet pet))
{
	if (ptree)
		InOrder(ptree->root, pf);
}

/* local list functions */
static void DeleteAllListNodes(Lnode *pn)
{
	Lnode *psave;

	while (pn) {
		psave = pn->next;
		free(pn);
		pn = psave;
	}
}

static Lnode *MakeListNode(Pet pet)
{
	Lnode *new_node;

	new_node = (Lnode *)malloc(sizeof(Lnode));
	if (new_node) {
		new_node->pet = pet;
		new_node->next = NULL;
	}

	return new_node;
}

static Lnode *LastListNode(const Lnode *pn)
{
	if (!pn)
		return NULL;

	while (pn->next)
		pn = pn->next;

	return (Lnode *)pn;
}

/* local tree functions */
static void InOrder(const Trnode *root, void (*pf)(Pet pet))
{
	if (root) {
		InOrder(root->left, pf);
		TraverseList(&root->item, pf);
		InOrder(root->right, pf);
	}
}

static void DeleteAllTreeNodes(Trnode *root)
{
	Trnode *pright;

	if (root) {
		pright = root->right;
		DeleteAllTreeNodes(root->left);
		DeleteList(&root->item);
		free(root);
		DeleteAllTreeNodes(pright);
	}
}

static void AddTreeNode(Trnode *new_node, Trnode *root)
{
	if (!new_node->item.start) {
		fprintf(stderr, "Null dereference error in AddTreeNode()\n");
		exit(1);
	}
	if (ToLeft(new_node->item.start->pet, root->item.start->pet)) {
		if (!root->left)
			root->left = new_node;
		else
			AddTreeNode(new_node, root->left);
	} else if (ToRight(new_node->item.start->pet, root->item.start->pet)) {
		if (!root->right)
			root->right = new_node;
		else
			AddTreeNode(new_node, root->right);
	} else {
		fprintf(stderr, "Location error in AddTreeNode()\n");
		exit(1);
	}
}

static bool ToLeft(Pet p1, Pet p2)
{
	if (strcmp(p1.petname, p2.petname) < 0)
		return true;
	else
		return false;
}

static bool ToRight(Pet p1, Pet p2)
{
	if (strcmp(p1.petname, p2.petname) > 0)
		return true;
	else
		return false;
}

static Trnode *MakeTreeNode(Pet pet)
{
	Trnode *new_node;

	new_node = (Trnode *)malloc(sizeof(Trnode));
	if (new_node) {
		InitializeList(&new_node->item);
		AddToList(pet, &new_node->item);
		new_node->left = NULL;
		new_node->right = NULL;
	}

	return new_node;
}

static Pair SeekItem(Pet pet, const Tree *ptree)
{
	Pair look;
	look.parent = NULL;
	look.child = ptree->root;

	if (!look.child)
		return look;

	while (look.child) {
		if (ToLeft(pet, look.child->item.start->pet)) {
			look.parent = look.child;
			look.child = look.child->left;
		} else if (ToRight(pet, look.child->item.start->pet)) {
			look.parent = look.child;
			look.child = look.child->right;
		} else
			/* must be same if not to left or right */
			/* look.child is address of node with item */
			break;
	}

	return look;
}

/* ptr is address of parent member pointing to target node */
static void DeleteTreeNode(Trnode **ptr)
{
	Trnode *temp;

	if (!(*ptr)->left) {
		temp = *ptr;
		*ptr = (*ptr)->right;
		DeleteList(&temp->item);
		free(temp);
	} else if (!(*ptr)->right) {
		temp = *ptr;
		*ptr = (*ptr)->left;
		DeleteList(&temp->item);
		free(temp);
	} else {
		/* deleted node has two children */
		/* find where to reattach right subtree */
		for (temp = (*ptr)->left; temp->right; temp = temp->right)
			continue;
		temp->right = (*ptr)->right;
		temp = *ptr;
		*ptr = (*ptr)->left;
		DeleteList(&temp->item);
		free(temp);
	}
}

static int CountAllNodes(const Trnode *pn)
{
	if (pn) {
		return ListItemCount(&pn->item) + CountAllNodes(pn->left) +
		       CountAllNodes(pn->right);
	}
	return 0;
}
