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
	printf("������ �Է��ϼ���: ");
	if (scanf("%d", &n))
	{
		printf("���: %d ���丮���� %lld�Դϴ�.\n", n, factorial_resursion(n));
		printf("�ݺ�: %d ���丮���� %lld�Դϴ�.\n", n, factorial_iteration(n));
	}
}