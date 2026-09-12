#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    if (!(cin >> N >> Q))
    {
        return 0;
    }

    vector<int> P(N + 1, 0);
    for (int i = 1; i <= N; ++i)
    {
        cin >> P[i];
    }

    vector<int> a(Q + 1, 0);
    for (int i = 1; i <= Q; ++i)
    {
        cin >> a[i];
    }

    // 處理被操作過的數字
    vector<bool> visited(N + 1, false);
    vector<int> aa(N + 1);
    int idx = N;
    for (int i = Q; i > 0; --i)
    {
        if (visited[a[i]] == false)
        {
            aa[idx--] = a[i];
            visited[a[i]] = true;
        }
    }

    // 未被操作過的數字
    idx = 1;
    for (int i = 1; i <= N; ++i)
    {
        if (visited[P[i]] == false)
        {
            aa[idx++] = P[i];
            visited[P[i]] = true;
        }
    }
    for (int i = 1; i <= N; ++i)
    {
        cout << aa[i] << ((i != N) ? " " : "");
    }

    return 0;
}