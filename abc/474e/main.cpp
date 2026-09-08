#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef struct
{
    LL A;
    LL B;
    LL diff;
} PRICE;

bool cmp(PRICE &a, PRICE &b)
{
    if (a.diff > b.diff)
        return true;

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T))
    {
        return 0;
    }

    int N;
    for (int i = 0; i < T; ++i)
    {
        cin >> N;
        vector<PRICE> p(N + 1, {0, 0, 0});
        LL Amin = LONG_LONG_MAX;
        for (int i = 1; i <= N; ++i)
        {
            cin >> p[i].A >> p[i].B;
            p[i].diff = p[i].A - p[i].B;
            Amin = min(Amin, p[i].A);
        }

        // 由大到小排序
        sort(p.begin() + 1, p.end(), cmp);
    
        // 建立 A 與 B 的前綴和陣列
        for (int i = 1; i <= N; ++i)
        {
            p[i].A = p[i - 1].A + p[i].A;
            p[i].B = p[i - 1].B + p[i].B;
        }

        // 從 x = 0 到 N 枚舉所有可能性，利用前綴和與公式以 O(1) 算出成本並取最小值
        LL minCost = LONG_LONG_MAX, cost;

        for (int j = 0; j <= N; ++j)
        {
            if (N >= 2 * j) // 即券足夠
            {
                cost = p[j].B + p[N].A - p[j].A;
            }
            else // 即券不足，需重複買 A_{min} 補齊
            {
                cost = p[j].B + p[N].A - p[j].A + (2 * j - N) * Amin;
            }

            if (cost < minCost)
            {
                minCost = cost;
            }
        }

        cout << minCost << ((i != (T - 1)) ? "\n" : "");
    }

    return 0;
}