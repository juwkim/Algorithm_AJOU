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
	printf("n을 입력하세요: ");
	if (scanf("%d", &n))
	{
		printf("n이 %d인 경우 군수열의 합 = ", n);
		long long sum = 0;
		while (n)
			sum += sig(n--);
		printf("%lld\n", sum);
	}
}