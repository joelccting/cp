#include <stdio.h>
int main()
{
    int m, n;
    if (2 != scanf("%d %d", &m, &n))
    {
        return 0;
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}