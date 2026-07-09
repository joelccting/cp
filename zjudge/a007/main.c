/* ZeroJudge a007. 判斷質數
 * 記憶體限制： 512 MB
 */

#include <stdio.h>

// 安全的模乘法，防止 (a * b) % n 溢位
ull mul_mod(ull a, ull b, ull m)
{
    return (ull)((__int128_t)a * b % m);
}

// 快速冪：計算 (a ^ b) % m
ull power(ull a, ull b, ull m)
{
    ull res = 1;
    a %= m;
    while (b > 0)
    {
        if (b % 2 == 1)
            res = mul_mod(res, a, m);
        a = mul_mod(a, a, m);
        b /= 2;
    }
    return res;
}

int miller_rabin(int n, int a)
{
    int d, x;

    if (a % n == 0)
        return 1;

    d = n - 1;
    while (d % 2 == 0)
        d /= 2;

    x = power(a, d, n);
    if (x == 1 || x == n - 1)
        return 1;

    while (d != n - 1)
    {
        x = mul_mod(x, x, n);
        d *= 2;
        if (x == n - 1)
            return 1;
        if (x == 1)
            return 0;
    }
    return 0;
}

int is_prime(int n)
{
    const int bases[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    int sz = sizeof(bases) / sizeof(int),
        i;

    for (i = 0; i < sz; ++i)
    {
        if (n == bases[i])
            return 1;
        if (0 == miller_rabin(n, bases[i]))
            return 0;
    }

    return 1;
}

int main()
{
    int n;

    while (scanf("%d%*[^\n]", &n) != EOF)
    {
        while (getchar() != '\n')
            ;

        if (is_prime(n))
            printf("質數\n");
        else
            printf("非質數\n");
    }
    return 0;
}

#if 0 /* TLE #2 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

#define LEN (2147483647)

void init(int *t, int sz)
{
    int i, j,
        sq = (int)sqrt((double)sz);

    t[0] = t[1] = 1; /*not prime*/
    t[2] = 0;        /* is prime */

    for (i = 2; i <= sq; ++i)
    {
        if (t[i] == 0)
        {
            for (j = i * i; j <= sz; j += i)
            {
                t[j] = 1;
            }
        }
    }
}

void prn(int *t, int sz)
{
    int i;
    for (i = 0; i <= sz; ++i)
    {
        printf("%d: %d\n", i, t[i]);
    }
}

int is_prime(int n, int *t, int sz)
{
    int i;

    for (i = 2; i <= sz; ++i)
    {
        if (t[i] == 0 && n % i == 0)
        {
            return 1; /* not a prime */
        }
    }

    return 0; /* is prime */
}

int main()
{
    int n, sz, *t;

    sz = (int)sqrt((double)LEN) + 1;
    t = (int *)calloc(sz, sizeof(int));
    assert(t != NULL);
    init(t, sz);
    // prn(t, sz);

    while (scanf("%d%*[^\n]", &n) != EOF)
    {
        while (getchar() != '\n')
            ;

        if (0 == is_prime(n, t, sz))
            printf("質數\n");
        else
            printf("非質數\n");
    }

    free(t);
    return 0;
}
#endif

#if 0 /* TLE */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int is_prime(int n)
{
    int i, sq = (int)sqrt((double)n);

    for (i = 2; i <= sq; ++i)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int n;

    while (scanf("%d%*[^\n]", &n) != EOF)
    {
        while (getchar() != '\n')
            ;

        if (is_prime(n))
            printf("質數\n");
        else
            printf("非質數\n");
    }
    return 0;
}

#endif