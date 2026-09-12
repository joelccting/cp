#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
int main()
{
    int N, S;
    LL L;
    if (!(cin >> N >> S >> L))
    {
        return 0;
    }

    vector<int> A(N + 1, 0);
    for (int i = 1; i < N; ++i)
    {
        cin >> A[i];
    }

    vector<LL> acc(N + 1, 0);
    for (int i = 2; i <= N; ++i)
    {
        acc[i] = A[i - 1] + acc[i - 1];
    }

    int max = INT_MIN;
    for (int i = 1; i <= S; ++i)
    {
        for (int j = S; j <= N; ++j)
        {
            if ((acc[S] - acc[i]) + (acc[j] - acc[i]) <= L)
            {
                if (max < j - i + 1)
                    max = j - i + 1;
            }

            if ((acc[j] - acc[S]) + (acc[j] - acc[i]) <= L)
            {
                if (max < j - i + 1)
                    max = j - i + 1;
            }
        }
    }

    cout << max;
    return 0;
}