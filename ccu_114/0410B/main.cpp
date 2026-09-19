#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int c[110];
LL dp[1000050];
#define MODULO (1000000007)

void f(int n, int x)
{
    dp[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = c[i]; j <= x; ++j)
        {
            dp[j] = (dp[j] + dp[j - c[i]]) % 1000000007;
        }
    }

    cout << dp[x];
}

int main()
{
    int n, x;
    if (!(cin >> n >> x))
        return 0;

    for (int i = 1; i <= n; ++i)
    {
        cin >> c[i];
    }

    f(n, x);

    return 0;
}