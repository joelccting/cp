#include <iostream>

using namespace std;
int a[50][50];

void sol(int x, int y, int H, int W)
{
    int cnt = 0;

    if (x + 1 < H)
    {
        cnt++;
    }
    if (y + 1 < W)
    {
        cnt++;
    }

    if (x - 1 > -1)
    {
        cnt++;
    }

    if (y - 1 > -1)
    {
        cnt++;
    }

    a[x][y] = cnt;
}

int main()
{
    int H, W;
    cin >> H >> W;
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            sol(i, j, H, W);
        }
    }
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            cout << a[i][j] << ((j < W - 1) ? " " : "");
        }
        cout << ((i < H - 1) ? "\n" : "");
    }
    return 0;
}