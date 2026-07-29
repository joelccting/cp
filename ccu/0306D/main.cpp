#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    if (!(cin >> n >> m))
        return 0;
    // char building[n][m + 1];
    vector<string> building(n);
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; ++i)
    {
        cin >> building[i];
    }

    int room_count = 0;
    stack<pair<int, int>> s;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (building[i][j] == '#')
                continue;

            if (visited[i][j] == false)
            {
                s.push({i, j});
                visited[i][j] = true;
                ++room_count;
                while (!s.empty())
                {
                    pair<int, int> p = s.top();
                    s.pop();
                    if (p.first + 1 < n && visited[p.first + 1][p.second] == false && building[p.first + 1][p.second] == '.')
                    {
                        visited[p.first + 1][p.second] = true;
                        s.push({p.first + 1, p.second});
                    }

                    if (p.first - 1 > -1 && visited[p.first - 1][p.second] == false && building[p.first - 1][p.second] == '.')
                    {
                        visited[p.first - 1][p.second] = true;
                        s.push({p.first - 1, p.second});
                    }

                    if (p.second + 1 < m && visited[p.first][p.second + 1] == false && building[p.first][p.second + 1] == '.')
                    {
                        visited[p.first][p.second + 1] = true;
                        s.push({p.first, p.second + 1});
                    }
                    if (p.second - 1 > -1 && visited[p.first][p.second - 1] == false && building[p.first][p.second - 1] == '.')
                    {
                        visited[p.first][p.second - 1] = true;
                        s.push({p.first, p.second - 1});
                    }
                }
            }
        }
    }
    cout << room_count;
    return 0;
}