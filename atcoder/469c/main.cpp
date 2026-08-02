#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    if (!(cin >> N))
        return 0;

    string S(N + 1, 0);
    cin >> S;
    int ans[N + 1];
    int idx = 0;
    for (int i = 0; i < N; ++i)
    {
        if (S[i] == 'o')
            continue;
        ans[idx++] = i + 1;
    }
    while (idx < N)
        ans[idx++] = N;
    for (int i = 0; i < N; ++i)
        cout << ans[i] << "\n";
    return 0;
}