#include <bits/stdc++.h>
using namespace std;
int cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        pair<int, int> t = {a, b};
        v.push_back(t);
    }
    sort(v.begin(), v.end(), cmp);
    int sz = v.size(), cnt = 1, now = v[0].second;
    for (int i = 1; i < sz; ++i)
    {
        if (now <= v[i].first)
        {
            ++cnt;
            now = v[i].second;
        }
    }
    cout << cnt;
    return 0;
}