#include <bits/stdc++.h>
using namespace std;
#define SZ (1 << 22)
vector<int> dp(SZ + 10, -1);
vector<int> a(1000010);

void f(int n)
{
    for (int i = 0; i <= 21; ++i)
    {
        for (int mask = 0; mask < SZ; ++mask)
        {
            dp[mask] = (dp[mask] != -1 ? dp[mask] : dp[mask & ~(1 << i)]);
        }
    }
}

int main()
{
    int n;
    if (!(cin >> n))
        return 0;

    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        dp[a[i]] = a[i];
    }

    f(n);
    for (int i = 1; i <= n; ++i)
    {
        cout << dp[~a[i] & ((1 << 22) - 1)] << " ";
    }

    return 0;
}