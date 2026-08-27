#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N (100010)
vector<int> dfn(N, 0);
vector<int> low(N, 0);
vector<bool> in_stack(N, false);
stack<int> stk;
int timestamp;
vector<vector<int>> adj(N);
vector<int> scc_id(N, 0);
int scc_cnt = 1;
vector<LL> scc_weight(N, 0);
vector<LL> weight(N, 0);
vector<LL> dp(N, -1);

void tarjan(int u)
{
    dfn[u] = low[u] = ++timestamp;
    stk.push(u);
    in_stack[u] = true;

    for (int v : adj[u])
    {
        if (dfn[v] == 0)
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (in_stack[v] == true)
        {
            low[u] = min(low[u], dfn[v]);
        }
    }

    if (dfn[u] == low[u])
    {
        while (true)
        {
            int x = stk.top();
            stk.pop();
            in_stack[x] = false;
            scc_id[x] = scc_cnt;
            scc_weight[scc_cnt] += weight[x];
            if (x == u)
            {
                scc_cnt++;
                break;
            }
        }
    }
}

LL get_up(vector<vector<int>> &dag, int u)
{
    if (dp[u] != -1)
    {
        return dp[u];
    }

    LL maximum = 0;
    for (LL v : dag[u])
    {
        maximum = max(maximum, get_up(dag, v));
    }
    dp[u] = scc_weight[u] + maximum;
    return dp[u];
}

void solve(int n, vector<vector<int>> &adj, vector<int> &in_degree, vector<LL> &dp)
{

    // 強連通分量 (SCC) 縮點
    for (int i = 1; i <= n; ++i)
    {
        if (dfn[i] == 0)
        {
            tarjan(i);
        }
    }

    // 建構新圖
    vector<vector<int>> dag(scc_cnt);
    for (int u = 1; u <= n; ++u)
    {
        for (auto v : adj[u])
            if (scc_id[u] != scc_id[v])
            {
                dag[scc_id[u]].push_back(scc_id[v]);
            }
    }

    // 拓撲排序
    LL maximum = 0;
    for (int i = 1; i < scc_cnt; ++i)
    {
        maximum = max(maximum, get_up(dag, i));
    }
    cout << maximum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, // 節點數量
        m; // 通道數量
    if (!(cin >> n >> m))
    {
        return 0;
    }

    for (int i = 1; i <= n; ++i)
    {
        cin >> weight[i];
    }

    vector<int> in_degree(n + 1, 0);
    for (int i = 1; i <= m; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        in_degree[b]++;
    }

    vector<LL> dp(n + 1);
    solve(n, adj, in_degree, dp);

    return 0;
}