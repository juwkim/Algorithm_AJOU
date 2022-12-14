#include <stdio.h>

int isSame(int a[], int b[], int a_size, int b_size)
{
	if (a_size != b_size)
		return 0;
	
	for (int i = 0; i < a_size; ++i)
	{
		if (a[i] != b[i])
			return 0;
	}
	return 1;
}

int main()
{
	int a[] = { 4, 7, 9, 3, 6 };
	int b[] = { 4, 7, 9, 3, 6 };
	//int b[] = { 10, 20, 30, 40, 50 };
	//int b[] = { 4, 7, 9, 3, 7};

	if (isSame(a, b, sizeof(a) / sizeof(int), sizeof(b) / sizeof(int)))
		printf("두 배열은 같다.");
	else
		printf("두 배열은 다르다.");
}