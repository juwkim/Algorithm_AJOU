#include <stdio.h>

void hanoi_tower(int n, char from, char mid, char to)
{
	if (n == 1)
		printf("원판 1을 %c에서 %c으로 옮긴다.\n", from, to);
	else
	{
		hanoi_tower(n - 1, from, to, mid);
		printf("원판 %d을 %c에서 %c으로 옮긴다.\n", n, from, to);
		hanoi_tower(n - 1, mid, from, to);
	}
}

int main()
{
	int n;
	printf("원판 개수를 입력하세요: ");
	if (scanf("%d", &n))
		hanoi_tower(n, 'A', 'B', 'C');
}