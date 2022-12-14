#include <stdio.h>
#define MAX 1000

long long dp[MAX] = { 0, };
long long fibo_resursion(int n)
{
	if (dp[n])
		return dp[n];
	if (n <= 1)
		return n;
	return fibo_resursion(n-1) + fibo_resursion(n - 2);
}

long long fibo_iteration(int n)
{
	int a = 0, b = 1;
	while (n--)
	{
		int tmp = a;
		a = b;
		b += tmp;
	}
	return a;
}

int main()
{
	int n;
	printf("n�� �Է��ϼ���: ");
	if (scanf("%d", &n))
	{
		printf("���\n");
		for (int i = 0; i <= n; ++i)
			printf("%lld ", fibo_resursion(i));
		printf("\n");

		printf("�ݺ�\n");
		for (int i = 0; i <= n; ++i)
			printf("%lld ", fibo_iteration(i));
		printf("\n");
	}
}