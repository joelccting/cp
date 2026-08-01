// Kruskal
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<pair<LL, pair<int, int>>> Edge;

int findParent(int i, vector<int> &parent)
{
    if (i == parent[i])
        return i;

    return parent[i] = findParent(parent[i], parent); ////路徑壓縮
    // return findParent(parent[i], parent); //路徑不壓縮
}

void merge(int a, int b, vector<int> &parent, vector<int> &size)
{
    int pa = findParent(a, parent);
    int pb = findParent(b, parent);
    if (pa == pb)
        return;

    // 啟發式合併
    if (size[pa] < size[pb])
        swap(pa, pb);
    size[pa] += size[pb];

    parent[pb] = pa;
}

bool isSameSet(int a, int b, vector<int> &parent)
{
    int pa = findParent(a, parent);
    int pb = findParent(b, parent);
    if (pa == pb)
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m))
    {
        return 0;
    }

    if (n == 1)
    {
        cout << "0";
        return 0;
    }

    vector<int> parent(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        parent[i] = i;
    }
    vector<int> size(n + 1, 1);
    Edge edge(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> edge[i].second.first >> edge[i].second.second >> edge[i].first;
    }
    // 1. 將所有邊照權重由小到大排序
    sort(edge.begin(), edge.end());
    LL cost = 0;
    int edge_count = 0;
    for (int i = 0; i < m; ++i)
    {
        // 2. 選擇沒被選過且權重最⼩的邊
        if (!isSameSet(edge[i].second.first, edge[i].second.second, parent))
        {
            // 3. 若加⼊此邊不會形成環(樹的性質)，則加⼊此邊
            cost += edge[i].first;
            merge(edge[i].second.first, edge[i].second.second, parent, size);
            edge_count++;
        }
    }

    if (edge_count != n - 1)
        cout << "IMPOSSIBLE";
    else
        cout << cost;

    return 0;
}