#include <bits/stdc++.h>
using namespace std;
const int M = (1E9 + 7);
typedef long long LL;
#define SZ (20000000)
LL S[SZ + 10];
LL x[SZ + 10];

LL inv(LL S)
{
    LL ret = 1;
    int t = M - 2;
    while (t)
    {
        if (t & 1)
        {
            ret *= S;
            ret %= M;
        }
        S *= S;
        S %= M;
        t >>= 1;
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x1, a, b;
    if (!(cin >> n >> x1 >> a >> b))
        return 0;

    S[0] = 1;
    x[1] = x1;
    for (int i = 1; i <= n; ++i)
    {
        S[i] = S[i - 1] * x[i];
        S[i] %= M;

        x[i + 1] = x[i] * a;
        x[i + 1] %= M;
        x[i + 1] += b;
        x[i + 1] %= M;
    }

    LL cur_inv = inv(S[n]);
    LL ans = 0;
    for (int i = n; i > 0; --i)
    {
        LL x_inv = cur_inv * S[i - 1];
        x_inv %= M;
        cur_inv = cur_inv * x[i];
        cur_inv %= M;
        ans += x_inv;
        ans %= M;
    }

    cout << ans;

    return 0;
}