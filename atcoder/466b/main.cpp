#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, M;
    cin >> N >> M;
    int S[M + 1] = {-1};
    for (int i = 0; i <= M; ++i) S[i] = -1;
    while (N--)
    {
        int c, s;
        cin >> c >> s;
        if (S[c] < s) S[c] = s;
    }

    for (int i = 1; i <= M; ++i)
    {
        cout << S[i] << " ";
    }
    return 0;
}