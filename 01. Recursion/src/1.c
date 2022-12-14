#include <stdio.h>

long long factorial_resursion(int n)
{
	if (n == 0)
		return 1;
	return n * factorial_resursion(n - 1);
}

long long factorial_iteration(int n)
{
	long long ret = 1;
	while (n)
		ret *= n--;
	return ret;
}

int main()
{
	int n;
	printf("정수를 입력하세요: ");
	if (scanf("%d", &n))
	{
		printf("재귀: %d 팩토리얼은 %lld입니다.\n", n, factorial_resursion(n));
		printf("반복: %d 팩토리얼은 %lld입니다.\n", n, factorial_iteration(n));
	}
}