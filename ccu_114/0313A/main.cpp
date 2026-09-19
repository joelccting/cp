// Dijkstra
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, int> PLLI;
// typedef vector<vector<pair<int, LL>>> adjacencyList;
typedef vector<vector<PLLI>> adjacencyList;

void dijkstra(adjacencyList &g, int start, vector<LL> &distance, vector<LL> &parent)
{
    distance[start] = 0;

    //C++ STL 預設採用字典序比較（Lexicographical Comparison）
    priority_queue<PLLI, vector<PLLI>, greater<PLLI>> pq;
    pq.push({0, start});
    while (!pq.empty())
    {
        //auto [d, u] = pq.top(); // C++17 結構化綁定 (Structured Binding)
        PLLI p = pq.top();
        LL d = p.first;
        int u = p.second;
        pq.pop();

        if (d > distance[u])
            continue;

        for (PLLI x : g[u])
        {
            LL w = x.first;
            int v = x.second;
            if (distance[u] < distance[v] - w)
            {
                distance[v] = distance[u] + w;
                parent[v] = u;
                pq.push({distance[v], v});
            }
        }
    }
}
int main()
{
    int n, m;
    if (!(cin >> n >> m))
    {
        return 0;
    }

    adjacencyList adj;
    adj.resize(n + 1);
    vector<LL> distance(n + 1, LLONG_MAX);
    vector<LL> parent(n + 1, -1);
    while (m--)
    {
        int u, v;
        LL w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }

    dijkstra(adj, 1, distance, parent);
    for (int i = 1; i <= n; ++i)
        cout << distance[i] << " ";

    return 0;
}