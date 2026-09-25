#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s1, s2;
    if (!(cin >> s1))
        return 0;
    if (!(cin >> s2))
        return 0;

    int len = min(s1.length(), s2.length()), ans = 0;
    for (int i = 0; i < len; ++i)
    {
        if (s1[i] == s2[i])
            continue;

        if (s1[i] < s2[i])
            ans = 1;
        else if (s1[i] > s2[i])
            ans = -1;
        break;
    }

    if (ans == 1)
        cout << s1 << s2;
    else
        cout << s2 << s1;
    return 0;
}