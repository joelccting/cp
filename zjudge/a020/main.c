// ZERO JUDGE a020. 身分證檢驗
#include <stdio.h>

int main()
{
    const int city[] = {
        10,
        11, 12, 13, 14, 15,
        16, 17, 34, 18, 19,
        20, 21, 22, 35, 23,
        24, 25, 26, 27, 28,
        29, 32, 30, 31, 33};
    char c[20] = {0};
    scanf("%s", c);
    int ci = city[c[0] - 'A'];
    int sum = ci / 10 + (ci % 10) * 9;
    int i;
    for (i = 1; i < 9; ++i)
    {
        //printf("%c-", c[i]);
        sum += (c[i] - '0') * (9 - i);
    }

    sum += (c[9] - '0');

    if (sum % 10 == 0)
    {
        printf("real");
    }
    else
    {
        printf("fake");
    }

    return 0;
}