// The problem asks for the minimum number of additional edges needed
// so that every vertex can reach every other vertex.

//#define DSU
#ifdef DSU

#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> VVI;

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

int main()
{
    int n, m;
    if (!(cin >> n >> m))
        return 0;

    vector<int> size(n + 1, 1);
    vector<int> parent(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        parent[i] = i;
    }

    for (int i = 0, a, b; i < m; ++i)
    {
        cin >> a >> b;
        merge(a, b, parent, size);
    }

    int numOfComponents = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (parent[i] == i)
            numOfComponents++;
    }

    cout << numOfComponents - 1;
    return 0;
}

#endif // DSU