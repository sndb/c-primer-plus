#include <stdio.h>

long rfact(int n);

int main(void)
{
	int n;
	long ans;

	scanf("%d", &n);
	ans = rfact(n);
	printf("%d! = %ld\n", n, ans);

	return 0;
}

long rfact(int n)
{
	long ans;

	if (n > 0)
		ans = n * rfact(n-1);
	else
		ans = 1;

	return ans;
}
