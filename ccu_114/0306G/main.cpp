#include <bits/stdc++.h>
using namespace std;

void solve(int n, vector<vector<int>> &adj, vector<int> &in_degree)
{
    vector<int> ans(n + 1, 0);
    // Min-Heap
    priority_queue<int, vector<int>> q;

    for (int i = 1; i <= n; ++i)
    {
        if (in_degree[i] == 0)
        {
            q.push(i);
        }
    }

    int idx = 1;
    while (!q.empty())
    {
        int u = q.top();
        q.pop();
        ans[idx++] = u;
        for (auto v : adj[u])
        {
            if (--in_degree[v] == 0)
            {
                q.push(v);
            }
        }
    }

    for (int i = n; i > 0; --i)
    {
        cout << ans[i] << ((i != 1) ? " " : "");
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    if (!(cin >> n >> m))
        return 0;

    vector<vector<int>> adj(n + 1);
    vector<int> in_degree(n + 1, 0);
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a); // 反向建圖
        in_degree[a]++;
    }

    solve(n, adj, in_degree);

    return 0;
}