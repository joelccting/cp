#include <bits/stdc++.h>
using namespace std;
// 建議：對於網格（Grid）BFS，通常不需要預先建圖（建立 adj），
// 直接在 bfs 的 while 迴圈內計算騎士的 8 個下一步並檢查邊界即可，
// 這樣能大幅節省記憶體與時間。
typedef struct
{
    int dx;
    int dy;
} Derivative;

const Derivative d[] = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
vector<pair<int, int>> adj[1010][1010];

void bfs(int startx, int starty, vector<vector<int>> &dist)
{
    queue<pair<int, int>> q;
    q.push({startx, starty});
    dist[startx][starty] = 0;
    while (!q.empty())
    {
        pair<int, int> u = q.front();
        q.pop();
        for (auto v : adj[u.first][u.second])
        {
            int x = v.first;
            int y = v.second;
            if (dist[x][y] != -1)
                continue;
            dist[x][y] = dist[u.first][u.second] + 1;
            q.push(v);
        }
    }
}

int main()
{
    int n;
    if (!(cin >> n))
        return 0;

    // 初始化

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            for (int k = 0; k < 8; ++k)
            {
                if ((0 < i + d[k].dx) && (i + d[k].dx <= n) &&
                    (0 < j + d[k].dy) && (j + d[k].dy <= n))
                {
                    adj[i][j].push_back({i + d[k].dx, j + d[k].dy});
                }
            }
        }
    }

    vector<vector<int>> distance(n + 1, vector<int>(n + 1, -1));
    bfs(1, 1, distance);

    // 輸出
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cout << distance[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}