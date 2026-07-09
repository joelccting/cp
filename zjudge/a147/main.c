/*
 * a147. Print it all
 */

#include <stdio.h>

int main()
{
    int n;
    int i;

    while (scanf("%d", &n) && n > 0)
    {
        for (i = 1; i < n; ++i)
        {
            if (i % 7)
                printf("%d ", i);
        }
        printf("\n");
    }

    return 0;
}