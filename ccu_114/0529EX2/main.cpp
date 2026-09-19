#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define MODULO(x, mod) ((x) % (mod) + (mod)) % (mod)

pair<LL, LL> exgcd(LL m, LL mi)
{
    if (!mi)
    {
        return {1, 0};
    }
    auto [x, y] = exgcd(mi, m % mi);
    return {y, x - (m / mi) * y};
}

int main()
{
    int n;
    if (!(cin >> n))
    {
        return 0;
    }

    LL r, m;
    cin >> r >> m;
    for (int i = 2; i <= n; ++i)
    {
        LL ri, mi;
        cin >> ri >> mi;
        pair<LL, LL> xy = exgcd(m, mi);
        LL g = gcd(m, mi);
        LL dr = ri - r;
        if (dr % g)
        {
            std::cout << -1;
            return 0;
        }

        LL k = dr / g;
        LL mod = mi / g;
        __int128_t x_real = xy.first * k;
        x_real = MODULO(x_real, mod);

        r = (r + x_real * m) % lcm(m, mi);
        m = lcm(m, mi);
    }

    std::cout << r;
    return 0;
}