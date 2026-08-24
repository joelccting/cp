// CF 1553 A. Digits Sum
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (!(cin >> t))
        return 0;
    for (int i = 0; i < t; ++i)
    {
        int n;
        cin >> n;
        int ans = n / 10;
        if (n % 10 == 9)
            ans++;
        cout << ans << "\n";
    }
    return 0;
}