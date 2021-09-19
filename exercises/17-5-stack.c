#include <stdio.h>
#include <stdlib.h>

#include "17-5-stack.h"

void StackInitialize(Stack *pstack)
{
	pstack->top = NULL;
	pstack->size = 0;
}

unsigned int StackItemCount(const Stack *pstack) { return pstack->size; }

bool StackIsEmpty(const Stack *pstack) { return pstack->size == 0; }

bool StackIsFull(const Stack *pstack)
{
	Node *pnode;
	bool status;

	if (pstack->size >= MAX_STACK_SIZE)
		return true;

	pnode = (Node *)malloc(sizeof(Node));
	if (!pnode) {
		fprintf(stderr, "Couldn't allocate enough space for a node\n");
		status = true;
	} else
		status = false;
	free(pnode);

	return status;
}

bool StackPushItem(Stack *pstack, const Item *pitem)
{
	Node *pnode;

	if (StackIsFull(pstack)) {
		fprintf(stderr, "Stack is full\n");
		return false;
	}

	pnode = (Node *)malloc(sizeof(Node));
	if (!pnode)
		return false;

	pnode->item = *pitem;
	pnode->next = pstack->top;
	pstack->top = pnode;
	pstack->size++;

	return true;
}

bool StackPopItem(Stack *pstack, Item *pitem)
{
	Node *psave;

	if (StackIsEmpty(pstack))
		return false;

	psave = pstack->top;
	*pitem = psave->item;
	pstack->top = psave->next;
	pstack->size--;
	free(psave);

	return true;
}

void StackFinish(Stack *pstack)
{
	Node *pnext;

	while (pstack->top) {
		pnext = pstack->top->next;
		free(pstack->top);
		pstack->top = pnext;
	}
	pstack->size = 0;
}
