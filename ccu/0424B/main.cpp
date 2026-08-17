#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define SZ (2010)
LL dp[SZ][SZ]; // dp[i][i]=0; len=1
void f(vector<int> &s, int n)
{
    for (int len = 2; len <= n; ++len)
    {
        for (int l = 1; l <= n; ++l)
        {
            int r = l + len - 1;
            if (r > n || r < 1)
                continue;
            dp[l][r] = min(dp[l + 1][r], dp[l][r - 1]) + (s[r] - s[l]);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n))
        return 0;

    vector<int> s(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> s[i];
    }
    sort(s.begin(), s.end());
    f(s, n);
    cout << dp[1][n];
    return 0;
}