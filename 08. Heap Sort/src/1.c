#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENT 200
typedef struct
{
	int key;
} element;

typedef struct
{
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;

void init(HeapType *h)
{
	h->heap_size = 0;
}

void insert_max_heap(HeapType *h, element item)
{
	int i = ++(h->heap_size);
	while (i != 1 && item.key > h->heap[i>>1].key)
	{
		h->heap[i] = h->heap[i>>1];
		i >>= 1;
	}
	h->heap[i] = item;
}

element delete_max_heap(HeapType *h)
{
	int parent = 1;
	int child = 2;
	element item = item = h->heap[1];
	element temp = h->heap[(h->heap_size)--];

	while (child <= h->heap_size)
	{
		if (child < h->heap_size && h->heap[child].key < h->heap[child + 1].key)
			child++;
		if (temp.key >= h->heap[child].key)
			break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child <<= 1;
	}
	h->heap[parent] = temp;
	return item;
}

void MaxheapSort(element a[], int n)
{
	int i;
	HeapType h;

	init(&h);
	for (i = 0; i < n; ++i)
		insert_max_heap(&h, a[i]);

	for (i = n-1; i >= 0; --i)
		a[i] = delete_max_heap(&h);
}

void verifyMaxheapSort (element * e)
{
	for (int i = 0; i < 9; ++i)
	{
		if (e[i].key > e[i+1].key)
		{
			printf("%d ��° ���� %d ��° ���� ������ �Ǿ����� �ʽ��ϴ�.\n", i+1, i+2);
			return;
		}
	}
	printf("Maxheap������ Ȯ�εǾ����ϴ�.\n\n");
}

void insert_min_heap (HeapType *h, element item) {
	int i = ++(h->heap_size);
	while (i != 1 && item.key < h->heap[i>>1].key)
	{
		h->heap[i] = h->heap[i>>1];
		i >>= 1;
	}
	h->heap[i] = item;
}

element delete_min_heap(HeapType *h)
{
	int parent = 1;
	int child = 2;
	element item = item = h->heap[1];
	element temp = h->heap[(h->heap_size)--];
	
	while (child <= h->heap_size)
	{
		if (child < h->heap_size && h->heap[child].key > h->heap[child + 1].key)
			child++;
		if (temp.key <= h->heap[child].key)
			break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child <<= 1;
	}
	h->heap[parent] = temp;
	return item;
}


void MinheapSort(element a[], int n)
{
	int i;
	HeapType h;

	init(&h);
	for (i = 0; i < n; ++i)
		insert_min_heap(&h, a[i]);

	for (i = n-1; i >= 0; --i)
		a[i] = delete_min_heap(&h);
}

void verifyMinheapSort (element * e)
{
	for (int i = 0; i < 9; ++i)
	{
		if (e[i].key < e[i+1].key)
		{
			printf("%d ��° ���� %d ��° ���� ������ �Ǿ����� �ʽ��ϴ�.\n", i + 1, i + 2);
			return;
		}
	}
	printf("Minheap������ Ȯ�εǾ����ϴ�.\n\n");
}

int main()
{
	int i;
	int size = 10;
	element e[size];

	srand(time(NULL));
	for (i = 0; i < size; ++i) e[i].key = rand() % 9 + 1;

	printf("���� �� Ű �� ���: ");
	for (i = 0; i < size; ++i) printf("%3d", e[i].key);
	printf("\n");
	verifyMaxheapSort(e);

	MaxheapSort(e, size);
	printf("Maxheap���� �� Ű �� ���: ");
	for (i = 0; i < size; ++i) printf("%3d", e[i].key);
	printf("\n");
	verifyMaxheapSort(e);	
	
	for (i = 0; i < size; ++i) e[i].key = rand() % 9 + 1;

	printf("���� �� Ű �� ���: ");
	for (i = 0; i < size; ++i) printf("%3d", e[i].key);
	printf("\n");
	verifyMinheapSort(e);

	MinheapSort(e, size);
	printf("Minheap���� �� Ű �� ���: ");
	for (i = 0; i < size; ++i) printf("%3d", e[i].key);
	printf("\n");
	verifyMinheapSort(e);

	return 0;
}