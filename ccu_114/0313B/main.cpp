// Bellman-Ford, using Edge List

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef struct
{
    int u; // from
    int v; // to
    LL w;
} Edge;

LL bellmanFord(vector<Edge> edges, int n, int m)
{
    vector<LL> distance(n + 1, LLONG_MIN);
    distance[1] = 0;
    // 1. 執行 V - 1 輪鬆弛
    for (int i = 1; i <= n - 1; ++i)
    {
        for (auto &it : edges)
        {
            if (distance[it.u] != LLONG_MIN && distance[it.v] < distance[it.u] + it.w)
            {
                distance[it.v] = distance[it.u] + it.w;
            }
        }
    }

    // 2. 第 V 輪：檢查是否還能繼續鬆弛
    vector<bool> in_positive_cycle(n + 1, false);
    for (auto &it : edges)
    {
        if (distance[it.u] != LLONG_MIN && distance[it.v] < distance[it.u] + it.w)
        {
            in_positive_cycle[it.v] = true;
        }
    }

    // Propagate the positive cycle state to see if it reaches target node n
    for (int i = 1; i <= n - 1; ++i)
    {
        for (const auto &it : edges)
        {
            if (in_positive_cycle[it.u])
            {
                in_positive_cycle[it.v] = true;
            }
        }
    }

    if (in_positive_cycle[n])
        return -1;

    return distance[n];
}

int main()
{
    int n, m;
    if (!(cin >> n >> m))
        return 0;

    vector<Edge> edgeList;
    edgeList.resize(m + 1);
    for (int i = 1; i <= m; ++i)
    {
        cin >> edgeList[i].u >> edgeList[i].v >> edgeList[i].w;
    }

    cout << bellmanFord(edgeList, n, m);
    return 0;
}