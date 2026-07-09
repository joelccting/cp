// a042. 平面圓形切割

#include <stdio.h>

int area(int n)
{
    if (1 == n)
        return 2;

    return area(n - 1) + 2 * (n - 1);
}

int main()
{
    int n = 3;
    while (scanf(" %d", &n) != EOF)
    {
        printf("%d\n", area(n));
    }
    
    return 0;
}