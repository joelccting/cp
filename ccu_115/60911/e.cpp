#include <bits/stdc++.h>
using namespace std;
const int LEN = 1E6 + 10;
int main()
{
    int k;
    if (!(cin >> k))
        return 0;

    k %= 26;
    if (k < 0)
        k += 26;

    string S(LEN, 0);
    getline(cin >> ws, S);

    int len = S.length();
    for (int i = 0; i < len; ++i)
    {
        if (!isalpha(S[i]))
            continue;

        char base;
        if (islower(S[i]))
            base = 'a';

        else
            base = 'A';

        int c = S[i] - base;
        c += k;
        c %= 26;
        S[i] = c + base;
    }
    for (int i = 0; i < len; ++i)
    {
        cout << S[i];
    }

    return 0;
}