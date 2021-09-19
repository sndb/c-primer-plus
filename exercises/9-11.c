#include <stdio.h>

void Fibonacci(int count)
{
	int n = 0;
	int next = 1;
	int next2;

	for (int i = 0; i < count; i++) {
		printf("%d\n", n);
		next2 = next;
		next = n;
		n = next2 + next;
	}
}

int main(void)
{
	Fibonacci(15);
	return 0;
}
