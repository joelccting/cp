#include <stdio.h>
int main()
{
    int n, m = 0;
    scanf("%d", &n);
    while (n)
    {
        m *= 10;
        m += n % 10;
        n /= 10;
    }

    while (m)
    {
        int d = m % 10;
        for (int i = 0; i < d; ++i)
        {
            printf("*");
        }
        printf("\n");
        m /= 10;
    }
    return 0;
}