#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    if (!(cin >> n))
    {
        return 0;
    }
    vector<int> a(n + 1, 0);
    vector<int> b(n + 1, 0);
    int div = 0, sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        div += a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> b[i];
    }

    for (int i = 1; i <= n; ++i)
    {
        sum += a[i] * b[i];
    }
    cout << sum / div;
    return 0;
}