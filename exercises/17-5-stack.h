#ifndef STACK_H_
#define STACK_H_

#include <stdbool.h>

#define MAX_STACK_SIZE 10

/* reset Item as appropriate */
typedef char Item;

typedef struct node {
	Item item;
	struct node *next;
} Node;

typedef struct stack {
	Node *top;
	unsigned int size;
} Stack;

void StackInitialize(Stack *pstack);
unsigned int StackItemCount(const Stack *pstack);
bool StackIsEmpty(const Stack *pstack);
bool StackIsFull(const Stack *pstack);
bool StackPushItem(Stack *pstack, const Item *pitem);
bool StackPopItem(Stack *pstack, Item *pitem);
void StackFinish(Stack *pstack);

#endif
