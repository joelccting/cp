#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    getline(cin, s);
    int len = s.length();
    int U = 0, L = 0, N = 0, B = 0;
    for (int i = 0; i < len; ++i)
    {
        if (isupper(s[i]))
            U++;
        else if (islower(s[i]))
        {
            L++;
            s[i] = toupper(s[i]);
        }
        else if (isspace(s[i]))
            B++;
        else
            N++;
    }
    cout << U << " " << L << " " << N << " " << B << "\n";
    cout << s;
    return 0;
}