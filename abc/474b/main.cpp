#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    if (!(cin >> N))
    {
        return 0;
    }

    int P[N + 1];
    for (int i = 1; i <= N; ++i)
    {
        cin >> P[i];
    }

    int b = 1,
        e = 10;
    for (int i = 1; i <= N; ++i)
    {

        if (P[i] < b || P[i] > e)
        {
            cout << "No";
            return 0;
        }

        if (i == e)
        {
            b += 10;
            e += 10;
        }
    }

    cout << "Yes";
    return 0;
}