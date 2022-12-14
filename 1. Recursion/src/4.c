#include <stdio.h>

double power(double x, int n)
{
	if (n == 0)
		return 1;
	if (n & 1)
		return x * power(x * x, n / 2);
	else
		return power(x * x, n / 2);
}

double slow_power(double x, int n)
{
	double ret = 1.0;
	while (n--)
		ret *= x;
	return ret;
}


int main()
{
	double x;
	int n;
	printf("�� ���� ���ڸ� �Է��ϼ���: ");
	if (scanf("%lf %d", &x, &n) == 2)
	{
		printf("��ͷ� ����: %f�� %d������ %f\n", x, n, power(x, n));
		printf("�ݺ����� ����: %f�� %d������ %f\n", x, n, slow_power(x, n));
	}
}