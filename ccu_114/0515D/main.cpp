#include <bits/stdc++.h>
using namespace std;
const int M = (1E9 + 7);
#define N (100)
typedef long long LL;
vector<vector<LL>> mtx(N + 1, vector<LL>(N + 1, 0));
vector<vector<LL>> ans(N + 1, vector<LL>(N + 1, 0));

void mul(vector<vector<LL>> &a, vector<vector<LL>> &b, int n)
{
    vector<vector<LL>> t(N + 1, vector<LL>(N + 1, 0));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            for (int k = 1; k <= n; ++k)
            {
                t[i][j] += a[i][k] * b[k][j] % M;
                t[i][j] %= M;
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            a[i][j] = t[i][j];
        }
    }
}

void fexp(int n, int k)
{
    for (int i = 1; i <= n; ++i)
    {
        ans[i][i] = 1;
    }

    while (k)
    {
        if (k & 1)
        {
            mul(ans, mtx, n);
        }
        mul(mtx, mtx, n);
        k >>= 1;
    }
}

int main()
{
    int n, m, k;
    if (!(cin >> n >> m >> k))
        return 0;
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        ++mtx[a][b];
    }
    fexp(n, k);
    cout << ans[1][n];
    return 0;
}