#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    if (!(cin >> N))
    {
        return 0;
    }

    vector<int> A(N + 1, 0);
    vector<int> ans(4, 0);
    for (int i = 1; i <= N; ++i)
    {
        cin >> A[i];
    }

    for (int i = 1; i < 4; ++i)
    {
        ans[i] = A[i];
    }

    sort(ans.begin() + 1, ans.end(), greater<int>());
    cout << ans[3] << "\n";

    for (int i = 4; i <= N; ++i)
    {
        if (A[i] >= ans[3])
        {
            ans[3] = A[i];
            sort(ans.begin() + 1, ans.end(), greater<int>());
        }
        cout << ans[3] << "\n";
    }
    return 0;
}