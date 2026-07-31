// Floyd-Warshall using Adjacency Matrix
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<vector<LL>> VVLL;
// MISTAKE: 1E9 too small as infinite
#define INF (1E18)
// MISTAKE: macro expansion should be fully wrapped in parentheses
#define min(x, y) (((x) < (y)) ? (x) : (y))

bool floydWarshall(VVLL &dist, int n)
{
    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            if (dist[i][k] > INF)
                continue;

            for (int j = 1; j <= n; ++j)
            {
                if (dist[k][j] > INF)
                    continue;

                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    bool negative_cycle = false;
    for (int i = 1; i <= n; ++i)
    {
        if (dist[i][i] < 0)
        {
            negative_cycle = true;
            break;
        }
    }

    return negative_cycle;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, q;
    if (!(cin >> n >> m >> q))
    {
        return 0;
    }

    // VVLL am(n + 1, vector<LL>(n + 1, 0));
    VVLL distance(n + 1, vector<LL>(n + 1, INF));
    for (int i = 1; i <= n; ++i)
    {
        distance[i][i] = 0;
    }

    for (int a, b, i = 1; i <= m; ++i)
    {
        LL c;
        cin >> a >> b >> c;
        if (a != b)
        {
            // MISTAKE: Multi-Edge is not dealt with
            // distance[a][b] = c;
            // distance[b][a] = c;
            distance[a][b] = min(distance[a][b], c);
            distance[b][a] = min(distance[b][a], c);
        }
    }

    if (floydWarshall(distance, n))
    {
        cout << "-1";
        return 0;
    }

    for (int a, b, i = 1; i <= q; ++i)
    {
        cin >> a >> b;
        if (distance[a][b] == INF)
            cout << "-1\n";
        else
            cout << distance[a][b] << "\n";
    }
    return 0;
}