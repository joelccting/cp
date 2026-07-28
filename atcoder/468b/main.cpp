#include <bits/stdc++.h>
using namespace std;

#if 1 // 26/07/26

int main()
{
    int M, D;
    cin >> M >> D;
    string S;
    cin >> S;
    vector<bool> v(M);
    for (int i = 0; i < M; ++i)
    {
        if (S[i] == 'G')
        {
            int from = (i - D) < 0 ? 0 : (i - D);
            int to = (i + D) > (M - 1) ? (M - 1) : (i + D);
            for (int j = from; j <= to; ++j)
            {
                if (v[j] != true)
                {
                    v[j] = true;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < M; ++i)
    {
        if (v[i] == false)
        {
            ++ans;
        }
    }
    cout << ans;
    return 0;
}
#endif // 26/07/26

#if 0  // 26/07/25
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
#endif // 26/07/25