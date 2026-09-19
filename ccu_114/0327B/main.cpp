#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    if (!(cin >> n >> m))
        return 0;
    vector<vector<LL>> a(n + 1, vector<LL>(m + 1));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> a[i][j];
        }
    }

    // Kadane's Algorithm
    // 將 2D 最大子矩陣和 簡化為 1D 最大子陣列和

    LL maxSum = LLONG_MIN, currentSum = 0;
    vector<LL> B(m + 1);
    // 固定上下邊界 (Top & Bottom)
    for (int i = 1; i <= n; ++i)
    {
        B.assign(m + 1, 0);
        for (int j = i; j <= n; ++j)
        {
            // 前綴和壓縮 (Column Prefix Sum)：
            currentSum = 0;

            for (int k = 1; k <= m; ++k)
            {
                B[k] += a[j][k];
               
                // 動態規劃對 B 執行尋找「最大連續子陣列和」
                currentSum = max(B[k], B[k] + currentSum);

                maxSum = max(maxSum, currentSum);
            }
        }
    }
    cout << maxSum;

    return 0;
}