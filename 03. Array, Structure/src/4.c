#include <stdio.h>

int main()
{
	printf("0에서 9까지의 정수를 20개 입력하세요.\n");
	
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
		printf("다시입력 <0 ~ 9> : ");
	} while (1);

	int idx = 0;
	for (int i = 0; i < 10; ++i)
	{
		if (buf[i] > buf[idx])
			idx = i;
	}
	printf("\n0~9 중 가장 많이 나온 수는 %d이고, %d번 나왔습니다.\n", idx, buf[idx]);
	return 0;
}