#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    set<int> s;
    while (n--)
    {
        int in;
        cin >> in;
        s.insert(in);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int query;
        cin >> query;
        // set<int>::iterator it = s.find(query);
        auto it = s.find(query);
        if (it == s.end())
        {
            auto it2 = s.begin();
            if (query < *it2)
            {
                cout << "NO\n";
            }
            else
            {
                it2 = s.lower_bound(query);
                --it2;
                cout << *it2 << "\n";
            }
        }
        else
        {
            cout << *it << "\n";
        }
    }
    return 0;
}