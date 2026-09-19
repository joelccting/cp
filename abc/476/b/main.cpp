#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    if (!(cin >> N))
    {
        return 0;
    }
    string S(N, 0), T(N, 0);
    cin >> S;
    cin >> T;
    int ans = 0;
    for (int i = 0; i < N; ++i)
    {
        if (T[i] == '*')
        {
            continue;
        }

        if (S[i] != T[i])
        {
            ans++;
        }
    }

    if (!ans) cout << "Yes";
    else cout << "No";
    return 0;
}