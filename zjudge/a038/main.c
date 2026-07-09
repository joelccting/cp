// a038. 數字翻轉

#include <stdio.h>
#define LEN (80)
char buf[LEN + 1];

int main()
{
    int n;
    scanf("%d", &n);
    int top = -1, i, j;

    if (n == 0)
    {
        printf("0");
        return 0;
    } 

    while (n)
    {
        buf[++top] = n % 10;
        n /= 10;
    }

    j = 0;
    while (buf[j] == 0)
    {
        ++j;
    }

    for (i = j; i <= top; ++i)
    {
        printf("%d", buf[i]);
    }

    return 0;
}