#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
#define MAX (1E18)
int main()
{
    int N;
    if (!(cin >> N))
    {
        return 0;
    }

    int A[N + 1], B[N + 1];
    LL W[N + 1];
    for (int i = 1; i <= N; ++i)
    {
        cin >> A[i];
    }
    for (int i = 1; i <= N; ++i)
    {
        cin >> B[i];
    }

    bool used = false;
    for (int i = 1; i <= N; ++i)
    {
        if (A[i] <= B[i])
        {
            W[i] = 1;
        }
        else
        {
            if (used == false)
            {
                W[i] = MAX;
                used = true;
            }
            else
            {
                W[i] = 1;
            }
        }
    }

    if (used == true)
    {
        cout << "Yes\n";
        for (int i = 1; i <= N; ++i)
        {
            cout << W[i] << ((i == N) ? "" : " ");
        }
    }
    else
    {
        cout << "No\n";
    }
    return 0;
}