#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x;
    cin >> x;
    int cnt = 0;
    for (int i = 1; i * i <= x; ++i)
    {
        if (x % i == 0)
        {
            if (i * i == x)
                cnt += 1;
            else
                cnt += 2;
        }
    }

    cout << cnt;
    return 0;
}