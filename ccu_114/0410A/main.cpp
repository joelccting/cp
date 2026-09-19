#include <bits/stdc++.h>
using namespace std;
#define MODULO (1000000007)
typedef long long LL;
LL dp[1000000];

void hb(int n)
{
    dp[0] = dp[1] = 1;

    for (int i = 2; i <= n; ++i)
    {
        for (int k = 1; k <= 6; ++k)
        {
            if (i >= k)
                dp[i] = (dp[i] + dp[i - k]) % MODULO;
        }
    }

    cout << dp[n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n))
        return 0;

    hb(n);
    return 0;
}