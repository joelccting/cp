// a003. 兩光法師占卜術

#include <stdio.h>

int main()
{
    int m, d, s;
    scanf("%d %d", &m, &d);
    s = (m * 2 + d) % 3;

    switch (s)
    {
    case 0:
        printf("普通");
        break;
    case 1:
        printf("吉");
        break;
    case 2:
        printf("大吉");
    default:
        break;
    }
    return 0;
}