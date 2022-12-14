#include <stdio.h>

int main()
{
	int a[] = { 5, 4, 1, 2, 3, 6 };
	int b[] = { 10, 20, 30, 40, 50, 60 };
	
	int a_size = sizeof(a) / sizeof(int);
	for (int i = 0; i < a_size; ++i)
		b[i] = a[i];

	int b_size = sizeof(b) / sizeof(int);
	printf("b[] =");
	for (int i = 0; i < b_size; ++i)
		printf(" %d", b[i]);
}