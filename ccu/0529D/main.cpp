#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
typedef long long LL;

int fastExponentiation(int base, int exp)
{
    int y = 1;
    int t = exp - 2;
    LL tmp;
    while (t)
    {
        if (t & 1)
        {
            tmp = 1LL * y;
            tmp *= base;
            tmp %= exp;
            y = (int)tmp;
        }

        tmp = 1LL * base;
        tmp *= base;
        tmp %= exp;
        base = (int)tmp;
        t >>= 1;
    }

    return y;
}

int r[10], m[10], Mi[10], y[10];
int main()
{
    int n;
    if (!(cin >> n))
        return 0;

    LL M = 1LL;
    for (int i = 1; i <= n; ++i)
    {
        cin >> r[i] >> m[i];
        M *= m[i];
    }

    for (int i = 1; i <= n; ++i)
    {
        Mi[i] = M / m[i];
        y[i] = fastExponentiation(Mi[i], m[i]);
    }

    LL x = 0;
    for (int i = 1; i <= n; ++i)
    {
        LL tmp = r[i];
        tmp *= Mi[i];
        tmp %= M;
        tmp *= y[i];
        tmp %= M;
        x += tmp;
        x %= M;
    }

    cout << x;

    return 0;
}