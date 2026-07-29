#include <bits/stdc++.h>
using namespace std;
int n, m;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
vector<string> building;
void dfs(int x, int y)
{
    // Mark current cell as visited by turning it into a wall
    building[x][y] = '#';
    for (int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // Bounds check + check if it's an unvisited floor cell
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && building[nx][ny] == '.')
        {
            dfs(nx, ny);
        }
    }
}

int main()
{
    if (!(cin >> n >> m))
        return 0;

    building.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> building[i];
    }

    int room_count = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (building[i][j] == '.')
            {
                dfs(i, j);
                ++room_count;
            }
        }
    }
    cout << room_count;
    return 0;
}