#include <bits/stdc++.h>
using namespace std;
int main()
{
    char c;
    if (!(cin >> c))
        return 0;

    int n;
    char s[] = {'B', 'Y', 'R'};
    switch (c)
    {
    case 'B':
        n = 0;
        break;
    case 'Y':
        n = 1;
        break;
    case 'R':
    default:
        n = 2;
        break;
    }
    n=(++n)%3;
    cout << s[n];
    return 0;
}