#include <stdio.h>

int main()
{
	printf("0���� 9������ ������ 20�� �Է��ϼ���.\n");
	
	int buf[10] = { 0, };
	int cnt = 20;
	int num;
	do {
		while (cnt && scanf("%d", &num) == 1 && 0 <= num && num <= 9)
		{
			buf[num]++;
			cnt--;
		}
		if (cnt == 0)
			break;
		printf("�ٽ��Է� <0 ~ 9> : ");
	} while (1);

	int idx = 0;
	for (int i = 0; i < 10; ++i)
	{
		if (buf[i] > buf[idx])
			idx = i;
	}
	printf("\n0~9 �� ���� ���� ���� ���� %d�̰�, %d�� ���Խ��ϴ�.\n", idx, buf[idx]);
	return 0;
}