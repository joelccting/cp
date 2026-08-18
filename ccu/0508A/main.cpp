#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef struct
{
    int v;
    int w;
} EP;

void f(vector<LL> &dp, vector<vector<EP>> &adj, vector<int> &in_degree, int n, int m)
{
    queue<int> q;

    for (int i = 1; i <= n; ++i)
    {
        if (in_degree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        // for (auto p : adj[u])
        for (const auto &p : adj[u])
        {
            dp[p.v] = // max({dp[p.v], dp[u] + p.w});
                max(dp[p.v], dp[u] + p.w);
            in_degree[p.v]--;
            if (in_degree[p.v] == 0)
                q.push(p.v);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, // 節點數量
        m; // 邊的數量

    if (!(cin >> n >> m))
        return 0;

    vector<vector<EP>> adj(n + 1);
    vector<int> in_degree(n + 1, 0);
    vector<LL> dp(n + 1, 0);
    // 點 u, v 之間有一條長度為 w 的單程路
    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        in_degree[v]++;
    }

    f(dp, adj, in_degree, n, m);

    LL ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}