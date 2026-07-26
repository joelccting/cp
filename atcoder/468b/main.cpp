#include <bits/stdc++.h>
using namespace std;
int main()
{
    int M, D;
    cin >> M >> D;
    string S;
    cin >> S;
    char L[M + 1] = {0}, R[M + 1] = {0};
    for (int i = 0; i < M; ++i)
    {
        if (S[i] == 'G')
        {
            R[i] = 'G';
            for (int j = 1; j <= D; ++j)
                if (i + j < M)
                    R[i + j] = 'G';
        }
    }

    for (int i = M - 1; i > -1; --i)
    {
        if (S[i] == 'G')
        {
            L[i] = 'G';
            for (int j = 1; j <= D; ++j)
                if (i - j > -1)
                    L[i - j] = 'G';
        }
    }
    for (int i = 0; i < M; ++i)
    {
        if (R[i] != 'G')
            R[i] = '.';
        if (L[i] != 'G')
            L[i] = '.';
    }
    // cout << R << "\n";
    // cout << L << "\n";
    int ans = 0;
    for (int i = 0; i < M; ++i)
    {
        if (R[i] != 'G' && L[i] != 'G')
        {
            ++ans;
        }
            
    }

    cout << ans;
    return 0;
}