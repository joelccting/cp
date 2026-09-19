// 多源 BFS（Multi-source BFS） 加上 雙重 BFS 的判斷問題（CSES - Monsters 經典題）
// 第一次 BFS（計算怪物最快到達各格的時間）
// 第二次 BFS（計算玩家逃脫路徑）

// 網格圖不需要額外建 adj 鄰接串列，直接在 BFS 內用 dx/dy 走訪即可。
// 此外在讀取字元建立 adj 時，若點靠近邊界，存取 map[nx][ny] 可能會存取出界（因為 map 只有到列 $n$）。

#include <bits/stdc++.h>
using namespace std;
typedef struct
{
    int x;
    int y;
} Point;

vector<Point> adj[1010][1010];
const int dx[] = {-1, 1, 0, 0},
          dy[] = {0, 0, -1, 1};

void bfs(vector<Point> start, vector<vector<int>> &dist)
{
    queue<Point> q;
    int sz = start.size();
    for (int i = 0; i < sz; ++i)
    {
        q.push(start[i]);
        dist[start[i].x][start[i].y] = 0;
    }

    while (!q.empty())
    {
        Point u = q.front();
        q.pop();

        for (auto v : adj[u.x][u.y])
        {
            if (dist[v.x][v.y] != INT_MAX)
                continue;

            dist[v.x][v.y] = dist[u.x][u.y] + 1;
            q.push(v);
        }
    }
}

void bfs2(vector<Point> start, vector<vector<int>> &pDist, vector<vector<int>> &mDist)
{
    queue<Point> q;
    int sz = start.size();
    for (int i = 0; i < sz; ++i)
    {
        q.push(start[i]);
        pDist[start[i].x][start[i].y] = 0;
    }

    while (!q.empty())
    {
        Point u = q.front();
        q.pop();

        for (auto v : adj[u.x][u.y])
        {
            if (pDist[v.x][v.y] != INT_MAX)
                continue;

            if (pDist[u.x][u.y] + 1 < mDist[v.x][v.y])
            {
                pDist[v.x][v.y] = pDist[u.x][u.y] + 1;
                q.push(v);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; // 分別代表地圖的長度與寬度

    if (!(cin >> n >> m))
        return 0;

    // 1-based indexing
    vector<string> map(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        string row;
        cin >> row;
        map[i] = " " + row;
    }

    vector<Point> monster;
    vector<Point> player;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            char c = map[i][j];
            if (c != '#')
                for (int k = 0; k < 4; ++k)
                {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (0 < nx && nx <= n && 0 < ny && ny <= m && map[nx][ny] != '#')
                    {
                        adj[i][j].push_back({nx, ny});
                    }
                }

            if (c == 'M')
                monster.push_back({i, j});

            if (c == 'A')
                player.push_back({i, j});
        }
    }

    vector<vector<int>> monster_dist(n + 1, vector<int>(m + 1, INT_MAX));
    vector<vector<int>> player_dist(n + 1, vector<int>(m + 1, INT_MAX));
    bfs(monster, monster_dist);
    bfs2(player, player_dist, monster_dist);

    bool isSuccess = false;

    for (int y = 1; y <= m; ++y)
    {
        if (map[1][y] != '#' && player_dist[1][y] != INT_MAX && player_dist[1][y] < monster_dist[1][y])
            isSuccess = true;
        if (map[n][y] != '#' && player_dist[n][y] != INT_MAX && player_dist[n][y] < monster_dist[n][y])
            isSuccess = true;
    }

    for (int x = 1; x <= n; ++x)
    {
        if (map[x][1] != '#' && player_dist[x][1] != INT_MAX && player_dist[x][1] < monster_dist[x][1])
            isSuccess = true;
        if (map[x][m] != '#' && player_dist[x][m] != INT_MAX && player_dist[x][m] < monster_dist[x][m])
            isSuccess = true;
    }

    if (isSuccess)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}