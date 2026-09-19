// Spanning tree with adjacency list
// 無負權樹直徑：兩次DFS
#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> VVI;
typedef vector<int> VI;
typedef vector<bool> VB;

#define RECURSION

#if defined(RECURSION)

void dfs(int u, int p, int d, const VVI &adj, VI &dist)
{
    dist[u] = d;
    for (int v : adj[u])
    {
        if (v != p)
        {
            dfs(v, u, d + 1, adj, dist);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n))
        return 0;

    VVI adj(n + 1);
    for (int a, b, i = 1; i < n; ++i)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    VI dist(n + 1, 0);

    // 第一次 DFS：找距離 1 最遠的點 farest
    dfs(1, 0, 0, adj, dist);
    int farest = max_element(dist.begin() + 1, dist.end()) - dist.begin();

    // 第二次 DFS：從 farest 出發找最遠距離（即樹直徑）
    dfs(farest, 0, 0, adj, dist);
    int diameter = *max_element(dist.begin() + 1, dist.end());

    cout << diameter << "\n";

    return 0;
}

#else
void dfs(int start, VVI &adj, VI &dist, VB &vis)
{
    stack<int> s;
    s.push(start);
    dist[start] = 0;
    vis[start] = true;
    while (!s.empty())
    {
        int u = s.top();
        s.pop();
        for (auto v : adj[u])
        {
            if (vis[v] == true)
                continue;

            dist[v] = dist[u] + 1;
            s.push(v);
            vis[v] = true;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    if (!(cin >> n))
        return 0;

    VVI aL(n + 1);
    for (int a, b, i = 1; i < n; ++i)
    {
        cin >> a >> b;
        aL[a].push_back(b);
        aL[b].push_back(a);
    }

    VI distance(n + 1, 0);
    VB visited(n + 1, false);
    dfs(1, aL, distance, visited);
    int d = distance[1];
    int farest = 1;
    for (int i = 2; i <= n; ++i)
    {
        if (distance[i] > d)
        {
            farest = i;
            d = distance[i];
        }
    }
    // cout << "The farest node: " << farest << "\n";

    fill(distance.begin(), distance.end(), 0);
    fill(visited.begin(), visited.end(), false);
    dfs(farest, aL, distance, visited);

    int maxDist = distance[farest];
    for (int i = 1; i <= n; ++i)
    {
        if (distance[i] > maxDist)
        {
            maxDist = distance[i];
        }
    }

    cout << maxDist;

    return 0;
}

#endif