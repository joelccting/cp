/* ZeroJudge b304 / UVa 673 Parentheses Balance
 */
#include <stdio.h>
#include <string.h>

/* #define DEBUG */
#define LEN (256)

#if defined(DEBUG)
#define dbg(fmt, ...) printf("[%d] " fmt, __LINE__, ##__VA_ARGS__)
#else
#define dbg(fmt, ...)
#endif

int main()
{
    int n, top = -1, len, i, res = 0;
    char s[LEN] = {0}, stack[LEN] = {0};

    scanf("%d", &n);
    /* scanf("%*[\r\n]"); */
    while (getchar() != '\n')
        ;

    while (n--)
    {
        if (fgets(s, LEN - 1, stdin) != NULL)
        {
            s[strcspn(s, "\r\n")] = 0;
            len = strlen(s);
            dbg("len=%d\n", len);
        }
        else
        {
            len = 0;
        }

        for (i = 0; i < len; ++i)
        {
            if (s[i] == '(' || s[i] == '[')
            {
                stack[++top] = s[i];
            }

            if (s[i] == ')')
            {
                if (top > -1 && stack[top] == '(')
                {
                    top--;
                }
                else
                {
                    res = 1;
                    break;
                }
            }

            if (s[i] == ']')
            {
                if (top > -1 && stack[top] == '[')
                {
                    top--;
                }
                else
                {
                    res = 1;
                    break;
                }
            }
        }

        if (res == 0 && top == -1)
            printf("Yes\n");
        else
            printf("No\n");

        top = -1;
        memset(stack, 0, LEN);
        res = 0;
    }
    return 0;
}
