// CF 1201B Zero Array
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n))
        return 0;

    long long sum = 0;
    int maxi = 0;
    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        maxi = max(maxi, a);
        sum += a;
    }

    if (sum % 2)
        cout << "NO";
    else if (maxi > sum / 2)
        cout << "NO";
    else
        cout << "YES";
    return 0;
}