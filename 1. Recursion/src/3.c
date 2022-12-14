#include <stdio.h>

void hanoi_tower(int n, char from, char mid, char to)
{
	if (n == 1)
		printf("���� 1�� %c���� %c���� �ű��.\n", from, to);
	else
	{
		hanoi_tower(n - 1, from, to, mid);
		printf("���� %d�� %c���� %c���� �ű��.\n", n, from, to);
		hanoi_tower(n - 1, mid, from, to);
	}
}

int main()
{
	int n;
	printf("���� ������ �Է��ϼ���: ");
	if (scanf("%d", &n))
		hanoi_tower(n, 'A', 'B', 'C');
}