/*a240. 第一題：1 / 17 小數第 n 位
 */

#include <stdio.h>

int main()
{
    int t, n, i, remainder = 1, digit, tmp;
    long long sum;

    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        remainder = 1;
        sum = 0;
        for (i = 0; i < n; ++i)
        {
            tmp = remainder * 10;
            digit = tmp / 17;
            remainder = tmp % 17;
            sum += digit;
        }
        printf("%d %lld\n", digit, sum);
    }
    return 0;
}