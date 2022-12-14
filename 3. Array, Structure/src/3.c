#include<stdio.h>

int main()
{
	int A[4][3] = {{46, 79, 78}, {35, 57, 28}, {43, 68, 76}, {56, 78, 98}};
	int B[4][3] = {{78, 35, 99}, {85, 82, 34}, {58, 69, 29}, {34, 59, 35}};
	int i, j;

	printf("두 행렬의 합\n");
	printf("---------------------\n");
	for (i = 0; i < 4; ++i)
	{
		for (j = 0; j < 3; ++j)
			printf("%4d", A[i][j] + B[i][j]);
		printf("\n");
	}
	printf("---------------------\n\n");

	printf("두 행렬의 차\n");
	printf("---------------------\n");
	for (i = 0; i < 4; ++i)
	{
		for (j = 0; j < 3; ++j)
			printf("%4d", A[i][j] - B[i][j]);
		printf("\n");
	}
	printf("---------------------\n");

	return 0;
}