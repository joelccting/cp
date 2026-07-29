#include <bits/stdc++.h>
using namespace std;

#if 1 // in stack
void dfs(int start, vector<vector<int>> &adj, vector<bool> &vis)
{
    stack<int> s;
    s.push(start);
    vis[start] = true;
    while (!s.empty())
    {
        int u = s.top();
        s.pop();
        for (auto v : adj[u])
        {
            if (vis[v]) continue;
            vis[v] = true;
            s.push(v);
        }
    }
}
#endif

#if 0 // in recursion
void dfs(int u, vector<vector<int>> &adj, vector<bool> &vis)
{
    vis[u] = true;
    for (auto v : adj[u])
    {
        if (!vis[v])
        {
            dfs(v, adj, vis);
        }
    }
}
#endif

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N + 1);
    vector<bool> visited(N + 1, false);
    while (M--)
    {
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }

    dfs(1, adj, visited);
    bool ans = true;
    for (int i = 1; i < N + 1; ++i)
    {
        if (!visited[i])
        {
            ans = false;
            break;
        }
    }

    if (ans)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
