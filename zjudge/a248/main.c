/*a248. 新手訓練 ~ 陣列應用
 */
#include <stdio.h>
#include <string.h>

#define LEN (10000 + 1000)
char s[LEN];

typedef unsigned long long ULL;

int main()
{
    ULL a, b, N, x;
    while (scanf("%llu %llu %llu", &a, &b, &N) == 3)
    {
        x = a / b;
        sprintf(s, "%lld.", x);
        int idx = strlen(s);
        x = a - b * x;
        for (int i = 0; i < N; ++i)
        {
            ULL y = 10 * x / b;
            s[idx++] = '0' + (int)y;
            x = 10 * x % b;
        }

        printf("%s\n", s);
        memset(s, 0, LEN);
    }

    return 0;
}