#include <stdio.h>

int split(int n)
{
    int L;

    if (n == 0)
    {
        return 1;
    }

    L = ((n - 1) * (n - 1) + (n - 1) + 2) / 2;
    return split(n - 1) + L;
}

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        printf("%d\n", split(n));
    }
    return 0;
}