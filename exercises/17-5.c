#include <ctype.h>
#include <stdio.h>

#include "17-5-stack.h"

int main(void)
{
	char ch;
	Stack stack;

	StackInitialize(&stack);
	while ((ch = getchar()) != EOF) {
		if (ch == '\n')
			break;
		StackPushItem(&stack, &ch);
	}
	while (StackPopItem(&stack, &ch)) {
		putchar(ch);
	}
	putchar('\n');
	StackFinish(&stack);

	return 0;
}
