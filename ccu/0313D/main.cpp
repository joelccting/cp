// 頂點數 50,000，任意兩點之間的邊數量達到 O(K*N^2)會爆掉
// 優化方向：K < 50，考慮拆點 / 虛擬點 (Virtual Nodes)
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, int> PLLI;

// C++17 標準庫<numeric>內建 GCD 函數 std::gcd
LL gcd(LL a, LL b)
{
    while (b != 0)
    {
        LL t = a % b;
        a = b;
        b = t;
    }
    return a;
}

void dijkstra(vector<vector<PLLI>> &g, int start, vector<LL> &distance, vector<LL> &parent)
{
    distance[start] = 0;

    // C++ STL 預設採用字典序比較（Lexicographical Comparison）
    priority_queue<PLLI, vector<PLLI>, greater<PLLI>> pq;
    pq.push({0LL, start});

    while (!pq.empty())
    {
        // auto [d, u] = pq.top(); // C++17 結構化綁定 (Structured Binding)
        PLLI p = pq.top();
        LL d = p.first;
        int u = p.second;
        pq.pop();

        if (d > distance[u])
            continue;
#if 1
        for (PLLI x : g[u])
        {
            LL w = x.first;
            int v = x.second;
            // if (distance[u] < distance[v] - w) // WRONG!
            if (distance[u] != LLONG_MAX && distance[u] + w < distance[v])
            {
                distance[v] = distance[u] + w;
                parent[v] = u;
                pq.push({distance[v], v});
            }
        }
#endif
    }
}

int main()
{
    int N, K, S, T;
    if (!(cin >> N >> K >> S >> T))
        return 0;

    // 實體點（星遺物）：創建 N 個點，編號 1 ~ N
    // 虛擬點（頻段 Hub）：針對 K 個頻段，創建 K 個虛擬點，編號 N+1 ~ N+K
    vector<LL> A(N + K + 1);
    for (int i = 1; i <= N; ++i)
    {
        cin >> A[i];
    }

    vector<LL> W(K + 1);
    for (int i = 1; i <= K; ++i)
    {
        cin >> A[N + i] >> W[i];
    }

    // Generate adjacency list
    vector<vector<PLLI>> adj(N + K + 1);
    for (int i = 1; i <= N; ++i)
    {
        for (int j = N + 1; j <= N + K; ++j)
        {
            if (gcd(A[i], A[j]) > 1)
            {
                adj[i].push_back({W[j - N] + A[i] / gcd(A[i], A[j]), j});
            }
        }
    }

    for (int i = N + 1; i <= N + K; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            if (gcd(A[i], A[j]) > 1)
            {
                adj[i].push_back({A[j] / gcd(A[i], A[j]), j});
            }
        }
    }

    vector<LL> distance(N + K + 1, LLONG_MAX);
    vector<LL> parent(N + K + 1, -1);
    dijkstra(adj, S, distance, parent);

    // 輸出結果
    if (distance[T] == LLONG_MAX)
    {
        cout << -1;
    }
    else
    {
        cout << distance[T];
    }

    return 0;
}