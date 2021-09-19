/* list.c -- functions supporting list operations */
#include <stdio.h>
#include <stdlib.h>

#include "17-2-list.h"

/* local function prototype */
static void CopyToNode(Item item, Node *pnode);

/* interface functions */
/* set the list to empty */
void InitializeList(List *plist)
{
	plist->head = NULL;
	plist->end = NULL;
}

/* returns true if list is empty */
bool ListIsEmpty(const List *plist)
{
	if (plist->head == NULL)
		return true;
	else
		return false;
}

/* returns true if list is full */
bool ListIsFull(const List *plist)
{
	Node *pt;
	bool full;

	pt = (Node *)malloc(sizeof(Node));
	full = (pt == NULL);
	free(pt);

	return full;
}

/* returns number of nodes */
unsigned int ListItemCount(const List *plist)
{
	unsigned int count = 0;
	Node *pnode = plist->head;

	while (pnode != NULL)
	{
		++count;
		pnode = pnode->next;
	}

	return count;
}

/* creates node to hold item and adds it to the end of */
/* the list pointed to by plist (slow implementation) */
bool AddItem(Item item, List *plist)
{
	Node *pnew;

	pnew = (Node *)malloc(sizeof(Node));
	if (pnew == NULL)
		return false;
	CopyToNode(item, pnew);
	pnew->next = NULL;

	if (plist->head == NULL)
		plist->head = pnew;
	else
		plist->end->next = pnew;
	plist->end = pnew;

	return true;
}

/* visit each node and execute function pointed to by pfun */
void Traverse(const List *plist, void (*pfun)(Item item))
{
	Node *pnode = plist->head;

	while (pnode != NULL)
	{
		(*pfun)(pnode->item);
		pnode = pnode->next;
	}
}

/* free memory allocated by malloc() */
/* set list pointer to NULL */
void EmptyTheList(List *plist)
{
	Node *psave;

	while (plist->head != NULL)
	{
		psave = plist->head->next;
		free(plist->head);
		plist->head = psave;
	}
	plist->end = NULL;
}

/* local function definition */
/* copies an item into a node */
static void CopyToNode(Item item, Node *pnode)
{
	pnode->item = item;
}
