// Kahn's Algorithm
#include <bits/stdc++.h>
using namespace std;
void kahn(int n, vector<vector<int>> &v, vector<int> &indeg)
{
    // queue<int> q;
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1; i <= n; ++i)
    {
        if (indeg[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int u = // q.front();
            q.top();
        q.pop();
        cout << u << " ";
        for (auto v : v[u])
        {
            if (--indeg[v] == 0)
                q.push(v);
        }
    }
}

int main()
{
    int n, m;
    if (!(cin >> n >> m))
        return 0;
    vector<vector<int>> adj(n + 1);
    vector<int> indegree(n + 1, 0);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        ++indegree[b];
    }
    kahn(n, adj, indegree);
    return 0;
}