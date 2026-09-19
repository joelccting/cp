#include <bits/stdc++.h>
using namespace std;
string w;
#define min(x, y, z) (((x) < (y)) ? ((x) < (z) ? (x) : (z)) : ((y) < (z) ? (y) : (z)))
void f(int sz)
{
    if (sz == 1)
    {
        cout << "0\n";
        return;
    }

    vector<vector<int>> dp(sz + 1, (vector<int>(sz + 1, 0)));
    for (int len = 2; len <= sz; ++len)
    {
        for (int i = 0; i <= sz - len; ++i) // 左界
        {
            int j = i + len - 1; // 右界

            if (w[i] == w[j])
            {
                dp[i][j] = dp[i + 1][j - 1];
            }
            else
            {
                dp[i][j] = 1+ min(dp[i + 1][j], dp[i][j - 1], dp[i + 1][j - 1]);
            }
        }
    }

    cout << dp[0][sz - 1] << "\n";
}

int main()
{
    int t;
    if (!(cin >> t))
        return 0;
    for (int i = 0; i < t; ++i)
    {
        cin >> w;
        f(w.length());
    }
    return 0;
}