#include<stdio.h>

long long sig(int num)
{
	if (num == 1)
		return 1;
	return num + sig(num - 1);
}

int main()
{
	int n;
	printf("n�� �Է��ϼ���: ");
	if (scanf("%d", &n))
	{
		printf("n�� %d�� ��� �������� �� = ", n);
		long long sum = 0;
		while (n)
			sum += sig(n--);
		printf("%lld\n", sum);
	}
}