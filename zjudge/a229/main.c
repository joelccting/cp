// ZeroJudge a229. 括號匹配問題

#include <stdio.h>

/*#define DEBUG*/
#if defined(DEBUG)
#define msg(fmt, ...) printf("[%d] " fmt, __LINE__, ##__VA_ARGS__)
#else
#define msg(fmt, ...)
#endif

void genp(char *a, int pos, int pair, int left, int right)
{
    msg("pos=%d\n", pos);
    if (pos == 2 * pair)
    {
        a[pos] = 0;
        printf("%s\n", a);
        return;
    }

    if (left < pair)
    {
        a[pos] = '(';
        genp(a, pos + 1, pair, left + 1, right);
    }

    if (right < left)
    {
        a[pos] = ')';
        genp(a, pos + 1, pair, left, right + 1);
    }
}

int main()
{
    int N;
    char c[30];
    while (scanf("%d", &N) != EOF)
    {
        while (getchar() != '\n')
            ;
        msg("N=%d\n", N);

        genp(c, 0, N, 0, 0);
    }
    return 0;
}