#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n))
        return 0;
    pair<int, int> a[n + 1];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].first >> a[i].second;
    }
    int q;
    cin >> q;
    int i, j;
    for (int k = 0; k < q; ++k)
    {
        cin >> i >> j;
        pair<int, int> t;
        t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
    for (int i = 0; i < n; ++i)
    {
        cout << a[i].first << " " << a[i].second << ((i != (n - 1)) ? "\n" : "");
    }
    return 0;
}