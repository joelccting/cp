/*ZeroJudge c123 / UVa 00514 - Rails
 */

#include <stdio.h>
#define SZ (1001)

/* #define DBG */
#if defined(DBG)
#define msg(fmt, ...) printf("[%s] " fmt, __func__, ##__VA_ARGS__)
#else
#define msg(fmt, ...)
#endif

int s[SZ];
int top;

void push(int n)
{
    if (top < SZ - 1)
    {
        s[++top] = n;
        msg("top=%d, n=%d\n", top, n);
    }
}

int pop(void)
{
    if (top > -1)
    {
        msg("top=%d, %d\n", top, s[top]);
        return s[top--];
    }

    return -1;
}

int gettop(void)
{
    if (-1 < top && top < SZ)
        return s[top];

    return -1;
}

int main()
{
    int N, first, a[SZ], i, income, flag = 1;
    char c;

    top = -1;

    while (1)
    {
        scanf("%d%*[^\n]", &N);
        while ((c = getchar()) != '\n' && c != EOF)
            ;
        msg("N=%d\n", N);
        if (0 == N)
            break;

        while (1)
        {
            scanf("%d", &first);
            msg("first=%d\n", first);
            if (0 == first)
                break;

            a[0] = first;
            for (i = 1; i < N; ++i)
            {
                scanf("%d", a + i);
            }
#if defined(DBG)
            for (i = 0; i < N; ++i)
                printf("%d ", a[i]);
            printf("\n");
#endif

            income = 1;
            top = -1;
            flag = 1;

            for (i = 0; i < N; ++i)
            {
                while (income <= a[i] && income <= N)
                    push(income++);

                if (gettop() == a[i])
                {
                    pop();
                }
                else
                {
                    flag = 0;
                    break;
                }
            }

            if (flag)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }

    return 0;
}