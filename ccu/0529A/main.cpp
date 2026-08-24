#include <bits/stdc++.h>
using namespace std;
const int M = (1E9 + 7);
int main()
{
    long long x;
    if (!(cin >> x))
        return 0;

    long long y = 1;
    int t = M - 2;
    while (t)
    {
        if (t & 1)
        {
            y *= x;
            y %= M;
        }
        x *= x;
        x %= M;
        t >>= 1;
    }

    cout << y;
    return 0;
}