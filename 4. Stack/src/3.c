#include <stdio.h>

int main()
{
    char c;
    char i = 0;
    char arr[1000];
    char prev = '0';
    printf("정수를 입력하시오: ");
    while (1)
    {
        scanf("%c", &c);
        if (c == '\n')
            break;
        if (c != prev)
        {
            arr[i++] = c;
            prev = c;
        }
    }

    printf("출력: ");
    for (int j = 0; j < i; ++j)
        printf("%c", arr[j]);
    
    printf("\n");
    return 0;
}