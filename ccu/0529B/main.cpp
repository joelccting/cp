#include <bits/stdc++.h>
using namespace std;
const int M = (1E9 + 7);
typedef long long LL;
LL power(LL base, LL exp, int mod)
{
    // if (base == 0 && exp == 0)
    // {
    //     return 1;
    // }

    LL ans = 1;
    while (exp)
    {
        if (exp & 1)
        {
            ans *= base;
            ans %= mod;
        }
        base *= base;
        base %= mod;
        exp >>= 1;
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t))
        return 0;
    for (int i = 0; i < t; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        LL E = power(b, c, M - 1);
        cout << power(a, E, M) << "\n";
    }

    return 0;
}