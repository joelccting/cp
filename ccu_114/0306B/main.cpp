// 求無權圖兩點最短路徑
#include <bits/stdc++.h>
using namespace std;
void bfs(int start, vector<vector<int>> &adj, vector<int> &dist)
{
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : adj[u])
        {
            if (dist[v] != -1)
                continue;

            dist[v] = dist[u] + 1;
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
    vector<int> distance(n + 1, -1);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs(1, adj, distance);

    cout << distance[n];
    return 0;
}