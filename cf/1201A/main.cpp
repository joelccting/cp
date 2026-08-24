// CF 1201A Important Exam
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m))
        return 0;
    int ans[m][5],
        scores[m];
    memset(ans, 0, sizeof(int) * m * 5);
    memset(scores, 0, sizeof(int) * m);

    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        int j = 0;
        while (s[j])
        {
            ++ans[j][s[j] - 'A'];
            ++j;
        }
    }

    for (int i = 0; i < m; ++i)
    {
        cin >> scores[i];
    }

    int sum = 0;
    for (int i = 0; i < m; ++i)
    {
        int maximum = 0;
        for (int j = 0; j < 5; ++j)
        {
            maximum = max(maximum, ans[i][j]);
        }
        //cout << maximum << "\n";
        sum += maximum * scores[i];
    }
    cout << sum;
    return 0;
}