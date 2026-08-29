#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define SZ (1000010)
int p;
LL fact[SZ];

LL inv(LL x)
{
    if (x % p == 0)
    {
        return 0;
    }

    LL y = 1;
    int t = p - 2;
    while (t)
    {
        if (t & 1)
        {
            y *= x;
            y %= p;
        }
        x *= x;
        x %= p;
        t >>= 1;
    }
    return y;
}

LL C(int n, int m)
{
    if (n < m)
    {
        return 0;
    }

    LL ret = fact[n] * inv(fact[m]);
    ret %= p;
    ret *= inv(fact[n - m]);
    ret %= p;
    return ret;
}

LL Lucas(LL n, LL m)
{
    if (m == 0)
    {
        return 1LL;
    }

    LL L1 = C(n % p, m % p);
    LL L2 = Lucas(n / p, m / p);
    return L1 * L2 % p;
}

int main()
{
    int t;
    if (!(cin >> t >> p))
    {
        return 0;
    }

    // 預處理 0 ~ p-1 的階乘
    fact[0] = 1;
    for (LL i = 1; i < p; ++i)
    {
        fact[i] = i * fact[i - 1] % p;
    }

    for (int i = 0; i < t; ++i)
    {
        LL n, m;
        cin >> n >> m;
        cout << Lucas(n, m) << "\n";
    }

    return 0;
}