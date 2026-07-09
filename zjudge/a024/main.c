//ZEROJUDGE a024 最大公因數(GCD)

#include <stdio.h>

int gcd(int x, int y)
{
    if (x % y == 0) 
    {
        return y;
    }

    return gcd(y, x % y);
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    if (a >= b) 
    {
        printf("%d", gcd(a, b));
    }
    else 
    {
        printf("%d", gcd(b, a));
    }

    return 0;
}