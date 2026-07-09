/* ZeroJudge b923. stack 堆疊的模板題
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN (100000)
#define SLEN (80)

void pop(int *a, int *top)
{
    if (*top > -1)
    {
        --(*top);
    }
}

void push(int *a, int *top, int entry)
{
    if (*top < LEN - 1)
    {
        a[++(*top)] = entry;
    }
}

void ontop(int *a, int top)
{
    if (top > -1)
    {
        printf("%d\n", a[top]);
    }
}

int main()
{
    int n, cnt, cmd[2];
    int a[LEN] = {0};
    char b[80], *pch;
    int top = -1;

    scanf("%d%*[^\n]", &n);
    getchar();

    while (n--)
    {
        fgets(b, SLEN - 1, stdin);
        b[strcspn(b, "\n")] = 0;

        pch = strtok(b, " ");

        cnt = 0;
        while (pch)
        {
            if (cnt < 2)
            {
                cmd[cnt++] = atoi(pch);
            }

            pch = strtok(NULL, " ");
        }

        switch (cmd[0])
        {
        case 1:
            pop(a, &top);
            break;
        case 2:
            ontop(a, top);
            break;
        case 3:
            push(a, &top, cmd[1]);
            break;
        default:
            break;
        }
    }
    return 0;
}