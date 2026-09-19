#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, M;
    cin >> N >> M;
    multiset<int, greater<int>> ms;
    vector<int> v;
    for (int i = 0; i < N; ++i)
    {
        int h;
        cin >> h;
        ms.insert(h);
    }
    for (int i = 0; i < M; ++i)
    {
        int t;
        cin >> t;
        v.push_back(t);
    }

    for (auto val : v)
    {
        auto it = ms.lower_bound(val);
        // cout << "val=" << val << "\n";
        if (it != ms.end())
        {
            cout << *it << "\n";
            ms.erase(it);
        }
        else
        {
            cout << "-1\n";
        }
    }
    return 0;
}