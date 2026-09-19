#include <bits/stdc++.h>
using namespace std;
#define MODULO (1000000007)

void dp(const int n, const int target)
{
    vector<int> dp(target + 5, 0);

    dp[0] = 1;
    for (int i = 1; i < n; ++i)
    {
        for (int j = target; j >= i; --j)
        {
            // 前 i 顆星星湊出甜度 j 的方案數 PLUS
            // 把第 i 顆星星放進這個瓶子(甜度 i 點)，所以剩下的甜度 (j - i)
            dp[j] = (dp[j] + dp[j - i]) % MODULO;
        }
    }

    cout << dp[target];
}

int main()
{
    int n;
    if (!(cin >> n))
        return 0;

    int S = n * (n + 1) / 2;
    if (1 == S % 2)
    {
        cout << "0";
        return 0;
    }

    dp(n, S / 2);

    return 0;
}