#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 100
typedef struct {
	int row;
	int col;
	int value;
} element;

typedef struct SparseMatrix {
	element data[MAX_TERMS];
	int rows;	// ���� ����
	int cols;	// ���� ����
	int terms; 	// 0�� �ƴ� ���� ����
} SparseMatrix;

// return 1 if a > b
// return 0 if a == b
// return -1 if a < b
int compareIDX(element s, element t)
{
	int num1 = s.row * MAX_TERMS + s.col;
	int num2 = t.row * MAX_TERMS + t.col;

	return (num1 > num2) - (num1 < num2);
}


void Sparse_matrix_add(SparseMatrix *a, SparseMatrix *b, SparseMatrix *c) // C=A+B
{
	if (a->rows != b->rows || a->cols != b->cols)
	{
		printf("������ũ�⿡��\n");
		return;
	}

	c->rows = a->rows;
	c->cols = a->rows;
	int curA = 0;
	int curB = 0;
	int curC = 0;
	while (curA < a->terms && curB < b->terms)
	{
		switch (compareIDX(a->data[curA], b->data[curB]))
		{
		case 1:
			c->data[curC] = b->data[curB++];
			break;
		case 0:
			c->data[curC] = a->data[curA++];
			c->data[curC].value += b->data[curB++].value;
			break;
		case -1:
			c->data[curC] = a->data[curA++];
			break;
		}
		curC++;
	}

	if (curA == a->terms)
	{
		while (curB < b->terms)
			c->data[curC++] = b->data[curB++];
	}
	else {
		while (curA < a->terms)
			c->data[curC++] = a->data[curA++];
	}

	c->terms = curC;
}

void printMatrix(SparseMatrix receivedMatrix) {
	int i, j, k; // i: ����� ��, j:����� ��, k:data �ε���  
	k = 0;

	//receivedMatrix.data�� ��ġ�� (i,j)�� �����Ѵٸ� value���� �Է�, �������� ���� �ÿ��� 0�� �Է�

	for (i = 0; i < receivedMatrix.rows; ++i)
	{
		for (j = 0; j < receivedMatrix.rows; ++j)
			if (i == receivedMatrix.data[k].row && j == receivedMatrix.data[k].col)
				printf("%6d", receivedMatrix.data[k++].value);
			else
				printf("%6d", 0);
		printf("\n");		
	}
	printf("\n");
}

void matrix_print(SparseMatrix a)
{
	printf("====================\n");
	for (int i = 0; i < a.terms; i++) {
		printf("(%d, %d, %d) \n", a.data[i].row, a.data[i].col, a.data[i].value);
	}
	printf("====================\n");
}

int main(void)
{
	SparseMatrix A = {
		{ { 1, 0, 8 },{ 3, 1, 2 },{ 4, 3, 9 },{ 4, 5, 2 },{ 5, 2, 5 } },
		6,
		6,
		5
	};
	SparseMatrix B = {
		{ { 0, 3, 7 },{ 1, 0, 9 },{ 1, 5, 8 },{ 3, 0, 6 },{ 3, 1, 5 },{ 4, 5, 1 },{ 5, 2, 2 } },
		6,
		6,
		7
	};
	SparseMatrix C;
	Sparse_matrix_add(&A, &B, &C);

	printf("<printf Matrix version1>\n\n");   // (��,��,��)���� ���
	matrix_print(A);
	matrix_print(B);
	matrix_print(C);

	printf("<printf Matrix version2>\n\n"); // 2���� �迭�� ���
	printMatrix(A);
	printMatrix(B);
	printMatrix(C);

	return 0;
}