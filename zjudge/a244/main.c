/*a244. 新手訓練 ~ for + if
 */

#include <stdio.h>

typedef long long LL;

int main()
{
    int N,
        a, b, c;
    LL r;

    scanf("%d", &N);
    while (N--)
    {
        scanf("%d%d%d", &a, &b, &c);

        switch (a)
        {
        case 1:
            r = b;
            r += c;
            printf("%lld\n", r);
            break;
        case 2:
            r = b;
            r -= c;
            printf("%lld\n", r);
            break;
        case 3:
            r = b;
            r *= c;
            printf("%lld\n", r);
            break;
        case 4:
            r = b;
            r /= c;
            printf("%lld\n", r);
            break;
        default:
            break;
        }
    }
    return 0;
}