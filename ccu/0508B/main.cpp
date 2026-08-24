#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector<vector<int>> &adj, vector<int> &ans)
{
    for (int v : adj[u])
    {
        dfs(v, adj, ans);
        ans[u] += ans[v] + 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;

    if (!(cin >> n))
        return 0;

    vector<vector<int>> adj(n + 1);
    vector<int> ans(n + 1, 0);
    for (int i = 2; i <= n; ++i)
    {
        int a;
        cin >> a;
        adj[a].push_back(i);
    }

    dfs(1, adj, ans);

    for (int i = 1; i <= n; ++i)
    {
        cout << ans[i] << " ";
    }

    return 0;
}