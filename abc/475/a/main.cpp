#include <bits/stdc++.h>
using namespace std;
int main()
{
    string S(15, 0);
    if (!(cin >> S))
    {
        return 0;
    }

    int l = S.length() - 1;
    int i = 0;
    while (l)
    {
        cout << S[i++];
        cout << "o";
        l--;
    }
    cout << S[i];
    return 0;
}