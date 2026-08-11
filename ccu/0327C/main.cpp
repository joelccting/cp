#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, Q;
    if (!(cin >> N >> Q))
        return 0;

    // 差分陣列（Difference Array）
    vector<int> diff(N + 2, 0);
    for (int i = 1; i <= Q; ++i)
    {
        int u, v;
        cin >> u >> v;
        diff[u]++;
        diff[v]--;
    }

    // 前綴和（Prefix Sum）
    vector<int> v(N + 1, 0);
    int maxCnt = 0, maxVilliage = 0;
    for (int i = 1; i <= N; ++i)
    {
        v[i] = v[i - 1] + diff[i];
        if (v[i] > maxCnt)
        {
            maxCnt = max(maxCnt, v[i]);
            maxVilliage = i;
        }
        
    }

    cout << maxVilliage;
    return 0;
}