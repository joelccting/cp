#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n))
        return 0;

    int len = n;
    int a[(int)1E5 + 10];
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    int k;
    cin >> k;
    // while (k)
    // {
    //     a[len--] = 0;
    //     k--;
    // }
    len -= k;
    int m;
    cin >> m;
    // if (m < len)
    // {
    // for (int i = m + 1; i <= len; ++i)
    //     a[i] = 0;
    // }
    // else
    if (m > len)
    {
        for (int i = len + 1; i <= m; ++i)
            a[i] = 0;
    }
    len = m;
    int v;
    cin >> v;
    a[len] = v;
    cout << len << "\n";
    for (int i = 1; i <= len; ++i)
        cout << a[i] << ((i == len) ? "" : " ");
    return 0;
}