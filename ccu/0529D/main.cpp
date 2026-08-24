#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
typedef long long LL;

LL fastExponentiation(LL base, LL exp, LL mod)
{
    LL y = 1LL;
    while (mod)
    {
        if (mod & 1)
        {
            y *= base;
            y %= exp;
        }

        base *= base;
        base %= exp;
        mod >>= 1;
    }

    return y;
}

LL r[10], m[10], Mi[10], y[10];

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
        y[i] = fastExponentiation(Mi[i], m[i], m[i] - 2);
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