/* list.c -- functions supporting list operations */
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

/* local function prototype */
static void CopyToNode(Item item, Node *pnode);

/* interface functions */
/* set the list to empty */
void InitializeList(List *plist)
{
	*plist = NULL;
}

/* returns true if list is empty */
bool ListIsEmpty(const List *plist)
{
	if (*plist == NULL)
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
	if (pt == NULL)
		full = true;
	else
		full = false;
	free(pt);

	return full;
}

/* returns number of nodes */
unsigned int ListItemCount(const List *plist)
{
	unsigned int count = 0;
	Node *pnode = *plist;

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
	Node *scan = *plist;
	
	pnew = (Node *)malloc(sizeof(Node));
	if (pnew == NULL)
		return false;

	CopyToNode(item, pnew);
	pnew->next = NULL;
	if (scan == NULL)
		*plist = pnew;
	else
	{
		while (scan->next != NULL)
			scan = scan->next;
		scan->next = pnew;
	}

	return true;
}

/* visit each node and execute function pointed to by pfun */
void Traverse(const List *plist, void (*pfun)(Item item))
{
	Node *pnode = *plist;

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

	while (*plist != NULL)
	{
		psave = (*plist)->next;
		free(*plist);
		*plist = psave;
	}
}

/* local function definition */
/* copies an item into a node */
static void CopyToNode(Item item, Node *pnode)
{
	pnode->item = item;
}
