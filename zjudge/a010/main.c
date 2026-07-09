// a010. 因數分解

#include <stdio.h>
#include <math.h>

#define dbg(s, b...)

int pwr(int *x, int i)
{
    int ret = 0;

    while (*x % i == 0)
    {
        *x /= i;
        ret++;
    }

    return ret;
}

int main()
{
    int x;
    int head = 0;
    scanf("%d", &x);

    int s = (int)sqrt(x);
    for (int i = 2; i <= s; ++i)
    {
        int n = pwr(&x, i);
        dbg("head=%d\n", head);
        if (n > 1)
        {
            if (head != 0)
            {
                printf(" * ");
            }

            printf("%d^%d", i, n);
            ++head;
        }
        else if (n == 1)
        {
            if (head != 0)
            {
                printf(" * ");
            }

            printf("%d", i);
            ++head;
        }
    }

    if (x != 1)
    {
        if (head != 0)
            printf(" * ");
        printf("%d", x);
    }

    return 0;
}