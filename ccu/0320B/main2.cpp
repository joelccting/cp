// use a classic traversal algorithm like DFS or BFS to visit
// every unvisited node and count how many times you have to
// start a new traversal.
#define BFS
#define DFS

#ifdef BFS

#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> VVI;

int getUnvisited(vector<bool> &v, int sz)
{
    int i = 1;
    while (i < sz && v[i])
        i++;

    if (i == sz)
        return -1;

    return i;
}

int bfs(VVI &adj)
{
    int cnt = 0;
    int sz = adj.size();
    vector<bool> visited(sz, false);

    int start = getUnvisited(visited, sz);
    while (start != -1)
    {
        queue<int> q;
        q.push(start);
        visited[start] = true;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (auto v : adj[u])
            {
                if (visited[v])
                    continue;

                visited[v] = true;
                q.push(v);
            }
        }
        cnt++;
        start = getUnvisited(visited, sz);
    }

    return cnt;
}

int main()
{
    int n, m;
    if (!(cin >> n >> m))
    {
        return 0;
    }

    VVI adj(n + 1);
    for (int i = 0, a, b; i < m; ++i)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout << bfs(adj) - 1;
    return 0;
}
#endif // BFS
