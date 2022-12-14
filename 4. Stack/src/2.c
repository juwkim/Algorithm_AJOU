#include <stdio.h>

int main()
{
    int N, i;
    printf("정수 배열의 크기: ");
    scanf("%d", &N);

    int arr[1000];
    printf("정수를 입력하시오: ");
    for (i = 0; i < N; ++i)
        scanf("%d", arr + i);

    printf("역순으로 출력된 정수 배열:");
    for (i = N-1; i >= 0; --i)
        printf(" %d", arr[i]);
    
    printf("\n");
    return 0;
}