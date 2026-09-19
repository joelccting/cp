#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MODULO(1E9 + 7);

void bexp(const LL a, const LL b)
{
    LL exp = b, t = a;
    LL ans = 1;
#if 0 /*冗餘的特判條件*/
    if (b == 0)
    {
        cout << "1\n";
        return;
    }
    else if (a == 0)
    {
        cout << "0\n";
        return;
    }
#endif
    while (exp)
    {
        if (exp & 1)
        {
            ans *= t;
            ans %= MODULO;
        }

        t *= t;
        t %= MODULO;
        exp >>= 1;
    }

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if (!(cin >> n))
        return 0;
    for (int i = 0; i < n; ++i)
    {
        LL a, b;
        cin >> a >> b;
        bexp(a % MODULO, b); // 預先對底數取模
    }
    return 0;
}