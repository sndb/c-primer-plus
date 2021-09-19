#include <stdbool.h>

/* reset Item as appropriate */
typedef int Item;

typedef struct node {
	Item item;
	struct node *next;
} Node;

typedef struct stack {
	Node top;
	unsigned int size;
} Stack;

void StackInitialize(Stack *pstack);
bool StackIsEmpty(const Stack *pstack);
bool StackIsFull(const Stack *pstack);
unsigned int StackItemCount(const Stack *pstack);
bool StackPushItem(Stack *pstack, const Item *pitem);
bool StackPopItem(Stack *pstack, Item *pitem);
bool StackFinish(Stack *pstack);
