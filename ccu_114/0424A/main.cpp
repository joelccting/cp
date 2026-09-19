#include <bits/stdc++.h>
using namespace std;

// 避免使用自訂巨集，優先使用 C++ 標準庫
//  #define max2(x, y) (((x) < (y)) ? (y) : (x))
//  #define max3(x, y, z) max2(max2((x), (y)), (z))

typedef long long LL;
#define SZ (100010)

// vector<vector<LL>> dp(SZ, vector<LL>(3, 0)); //會在程式一啟動時就在 Heap 配置大型動態記憶體
LL dp[SZ][3];

// 空間複雜度優化
// vector<LL> a(SZ, 0), b(SZ, 0), c(SZ, 0);
LL a, b, c;

void f(int i)
{
    // for (int i = 1; i <= N; ++i)
    {
        // dp[i][0] = a[i] + max2(dp[i - 1][1], dp[i - 1][2]);
        // dp[i][1] = b[i] + max2(dp[i - 1][0], dp[i - 1][2]);
        // dp[i][2] = c[i] + max2(dp[i - 1][0], dp[i - 1][1]);
        dp[i][0] = a + max({dp[i - 1][1], dp[i - 1][2]});
        dp[i][1] = b + max({dp[i - 1][0], dp[i - 1][2]});
        dp[i][2] = c + max({dp[i - 1][0], dp[i - 1][1]});
    }

    // cout << max3(dp[N][0], dp[N][1], dp[N][2]);
    // cout << max({dp[N][0], dp[N][1], dp[N][2]});
}

int main()
{
    int N;
    if (!(cin >> N))
        return 0;

    for (int i = 1; i <= N; ++i)
    {
        //        cin >> a[i] >> b[i] >> c[i];
        cin >> a >> b >> c;
        f(i);
    }

    cout << max({dp[N][0], dp[N][1], dp[N][2]});
    return 0;
}