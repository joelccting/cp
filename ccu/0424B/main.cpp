#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define SZ (2010)
// LL dp[SZ][SZ]; // dp[i][i]=0; len=1
LL dp[2][SZ];

void f(vector<int> &s, int n)
{
    for (int len = 2; len <= n; ++len)
    {
        // for (int l = 1; l <= n; ++l)
        for (int l = 1; l <= n - len + 1; ++l)
        {
            int r = l + len - 1;
            // if (r > n || r < 1)
            //     continue;
            dp[len % 2][l] = min(dp[1 - (len % 2)][l + 1], dp[1 - (len % 2)][l]) + (s[r] - s[l]);
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
    cout << dp[n % 2][1];
    return 0;
}