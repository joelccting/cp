#include <stdio.h>

int f(int n)
{
    if (n == 1)
        return 1;

    if (n & 1)
        return f(n - 1) + f(n + 1);

    return f(n / 2);
}

int main()
{
    int x;
    scanf("%d", &x);
    printf("%d", f(x));
    return 0;
}