#include <stdio.h>
#include <string.h>
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
        printf("%d\n", m % 10);
        m /= 10;
    }

    return 0;
}