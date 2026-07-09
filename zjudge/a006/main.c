// ZERO JUDGE a006 一元二次方程式
#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, c, d;
    scanf("%d %d %d", &a, &b, &c);
    d = b * b - 4 * a * c;
    if (d == 0)
    {
        printf("Two same roots x=%d", (-1) * b / (2 * a));
    }
    else if (d > 0)
    {
        printf("Two different roots x1=%d , x2=%d", ((-1) * b + (int)sqrt(d)) / (2 * a), ((-1) * b - (int)sqrt(d)) / (2 * a));
    }
    else
    {
        printf("No real root");
    }
    return 0;
}