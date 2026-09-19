#include <bits/stdc++.h>
using namespace std;
#define MODULO (1000000007)
typedef long long LL;
// LL dp[100005][105]; // 狀態dp[i][j] 為 第 i 分鐘、心率為 j 的方案總數
LL dp[2][105];

void f(vector<int> &x, int n, int m)
{
    // 初始化
    for (int j = 1; j <= m; ++j)
    {
        if (x[1] == 0)
        {
            dp[1][j] = 1;
        }
        else
        {
            dp[1][j] = 0;
        }
    }
    if (x[1] != 0)
        dp[1][x[1]] = 1;

    for (int i = 2; i <= n; ++i)
    {
        // 清空舊資料
        memset(dp[i % 2], 0, 105 * sizeof(LL));
        for (int j = 1; j <= m; ++j)
        {

            LL sum = 0;
            if ((0 == x[i]) || ((x[i] != 0) && (j == x[i])))
            {

                if (j > 1)
                {
                    sum += dp[(i - 1) % 2][j - 1];
                    sum %= MODULO;
                }

                if (j < m)
                {
                    sum += dp[(i - 1) % 2][j + 1];
                    sum %= MODULO;
                }

                sum += dp[(i - 1) % 2][j];
                dp[i % 2][j] = sum % MODULO;
            }
            else
            {
                dp[i % 2][j] = 0;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m))
        return 0;

    vector<int> x(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> x[i];
    }

    f(x, n, m);
    LL ans = 0;
    for (int i = 1; i <= m; ++i)
    {
        ans += dp[n % 2][i];
        ans %= MODULO;
    }
    cout << ans;
    return 0;
}