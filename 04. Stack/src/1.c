#include <stdio.h>

int main()
{
    char buf[300];
    printf("문자를 입력하세요: ");

    int r = -1;
    char *str = buf;
    while (1)
    {
        scanf("%c", str);
        if (*str == '\n')
            break;
        else if ('A' <= *str && *str <= 'Z')
            *str += 32;
        else if ('a' > *str || *str > 'z')
            continue;            
        r++;
        str++;
    }

    int l = 0;
    int flag = 1;
    while (l < r && buf[l] == buf[r])
    {
        l++;
        r--;
    }

    if (l < r)
        printf("FALSE\n");
    else
        printf("TRUE\n");
    return 0;
}