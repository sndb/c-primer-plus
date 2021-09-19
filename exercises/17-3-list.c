/* list.c -- functions supporting list operations */
#include <stdio.h>
#include <stdlib.h>

#include "17-3-list.h"

/* interface functions */
/* set the list to empty */
void InitializeList(List *plist)
{
	plist->items = 0;
}

/* returns true if list is empty */
bool ListIsEmpty(const List *plist)
{
	return plist->items == 0;
}

/* returns true if list is full */
bool ListIsFull(const List *plist)
{
	return plist->items == MAXSIZE;
}

/* returns number of items */
unsigned int ListItemCount(const List *plist)
{
	return plist->items;
}

/* adds item to the end of the list pointed to by plist */
bool AddItem(Item item, List *plist)
{
	if (ListIsFull(plist))
		return false;

	plist->entries[plist->items] = item;
	plist->items++;

	return true;
}

/* visit each node and execute function pointed to by pfun */
void Traverse(const List *plist, void (*pfun)(Item item))
{
	for (int i = 0; i < plist->items; i++)
		(*pfun)(plist->entries[i]);
}

/* set number of items to zero */
void EmptyTheList(List *plist)
{
	plist->items = 0;
}
