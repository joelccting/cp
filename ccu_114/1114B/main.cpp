#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
    int n;
    cin >> n;
    map<LL, int> mp;
    int i = 1;
    while (n--)
    {
        LL a;
        cin >> a;
        pair<LL, int> p(a, i++);
        mp.insert(p);
    }
    int q;
    cin >> q;
    while (q--)
    {
        LL key;
        cin >> key;
        auto it = mp.find(key);
        if (it != mp.end())
        {
            cout << it->second << "\n";
            mp.erase(it);
        }
        else
        {
            cout << "solved\n";
        }
    }
    return 0;
}