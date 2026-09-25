#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

// compute 0 ^ 1 ^ ... ^ n
LL f(LL n)
{
    LL ret;
    switch (n % 4)
    {
    case 0:
        ret = n;
        break;
    case 1:
        ret = 1;
        break;
    case 2:
        ret = n + 1;
        break;
    case 3:
    default:
        ret = 0;
        break;
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    if (!(cin >> q))
        return 0;

    for (int i = 0; i < q; ++i)
    {
        LL L, R;
        cin >> L >> R;

        cout << (f(L - 1) ^ f(R)) << "\n";
    }
    return 0;
}