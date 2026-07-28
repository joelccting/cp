// Bit Force（位元枚舉）
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
    int n;
    LL x;
    cin >> n >> x;
    int v[20];
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    int cnt = 0;
    for (int mask = 0; mask < (1 << n); ++mask)
    {
        LL sum = 0;
        for (int i = 0; i < n; ++i)
        {
            if (mask & (1 << i))
            {
                sum += v[i];
            }
        }

        if (sum == x)
            cnt++;
    }

    cout << cnt;
    return 0;
}