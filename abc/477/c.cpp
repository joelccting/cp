#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int Q;
    string S, T;
    if (!(cin >> Q >> S >> T))
        return 0;

    int slen = S.length();
    int tlen = T.length();
    int range = slen - tlen;
    vector<int> P;
    for (int i = 0; i <= range; ++i)
    {
        if (!strncmp(&S[i], &T[0], tlen))
            P.push_back(i);
    }

    while (Q)
    {
        int L, R; // 1-based
        cin >> L >> R;
        L--; // 0-based
        R--;

        do
        {
            if ((R - L + 1) < tlen)
            {
                cout << "No\n";
                break;
            }
            int bound = R - tlen + 1;
            vector<int>::iterator it = lower_bound(P.begin(), P.end(), L);
            if (it == P.end() || *it > bound)
                cout << "No\n";
            else
                cout << "Yes\n";
        } while (0);
        Q--;
    }
    return 0;
}