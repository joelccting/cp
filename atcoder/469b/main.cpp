#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    if (!(cin >> N))
        return 0;
    string S(N + 1, 0);
    cin >> S;

    int cnt = 0;
    for (int i = 0; i < N; ++i)
    {
        if (S[i] == 'o')
            continue;

        if ((i == 0 || S[i - 1] == 'x') && (i == N - 1 || S[i + 1] == 'x'))
            ++cnt;
    }

    cout << cnt;

    return 0;
}