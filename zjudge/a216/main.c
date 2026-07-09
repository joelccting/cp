/* a216. 數數愛明明
 */

#include <stdio.h>

typedef long long LL;

LL f(LL n)
{
    if (n == 1)
        return 1;
    return n + f(n - 1);
}

LL g(LL n)
{
    if (n == 1)
        return 1;

    return f(n) + g(n - 1);
}

int main()
{
    int n;

    while (scanf("%d", &n) != EOF)
    {
        printf("%lld %lld\n", f(n), g(n));
    }

    return 0;
}