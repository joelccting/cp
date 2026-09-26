#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
    int N;
    LL D;
    if (!(cin >> N >> D))
        return 0;

    vector<LL> X(N + 1, 0);
    vector<bool> M(N + 1, false);
    for (int i = 1; i <= N; ++i)
        cin >> X[i];

    int cnt, ans = 0;
    for (int i = 1; i <= N; ++i)
    {
        cnt = 0;
        for (int j = 1; j <= N; ++j)
        {
            if (j == i)
                continue;

            if (abs(X[i] - X[j]) >= D)
                cnt++;
        }

        if (cnt == N - 1)
        {
            ans++;
            M[i] = true;
        }
    }

    cout << ans << "\n";
    for (int i = 1; i <= N; ++i)
    {
        if (M[i])
            cout << i << " ";
    }

    return 0;
}