#include <bits/stdc++.h>
using namespace std;
int main()
{
    string S;
    if (!(cin >> S))
    {
        return 0;
    }

    int n = S.length();
    if (S[n - 1] == 'e')
    {
        cout << S << "r";
    }
    else
    {
         cout << S << "er";
    }
    return 0;
}