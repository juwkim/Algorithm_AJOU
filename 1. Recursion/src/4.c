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
	printf("두 개의 숫자를 입력하세요: ");
	if (scanf("%lf %d", &x, &n) == 2)
	{
		printf("재귀로 구현: %f의 %d제곱은 %f\n", x, n, power(x, n));
		printf("반복으로 구현: %f의 %d제곱은 %f\n", x, n, slow_power(x, n));
	}
}