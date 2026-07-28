#include <bits/stdc++.h>
using namespace std;
int cmp(pair<int, int> &pa, pair<int, int> &pb)
{
    return (pa.second < pb.second);
}

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i)
    {
        pair<int, int> p;
        cin >> p.first >> p.second;
        v.push_back(p);
    }
    sort(v.begin(), v.end(), cmp);
    int sz = v.size();
    int cnt = 1;
    int t = v[0].second;
    for (int i = 1; i < sz; ++i)
    {
        if (t > v[i].first)
            continue;

        cnt++;
        t = v[i].second;
    }
    cout << cnt;
    return 0;
}