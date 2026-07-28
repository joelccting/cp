#include <bits/stdc++.h>
using namespace std;
typedef struct
{
    int val;
    int id;
} Point;

int main()
{
    int n;
    if (!(cin >> n))
        return 0;
    vector<Point> vx(n), vy(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vx[i].val;
        vx[i].id = i + 1;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> vy[i].val;
        vy[i].id = i + 1;
    }

    // Lambda 表示法 (since C++11)
    auto cmp = [](const Point &a, const Point &b)
    {
        return a.val < b.val;
    };

    sort(vx.begin(), vx.end(), cmp);
    sort(vy.begin(), vy.end(), cmp);
    vector<int> ans(n + 1);
    for (int i = 0; i < n; ++i)
    {
        ans[vx[i].id] = vy[i].id;
    }
    for (int i = 1; i <= n; ++i)
    {
        cout << ans[i] << "\n";
    }
}

// 26/07/28 The following code passed, but it needs to be improved.
#if 0 
int cmp(pair<int, pair<int, int>> pa, pair<int, pair<int, int>> pb)
{
    return pa.first < pb.first;
}

int cmp2(pair<int, pair<int, int>> pa, pair<int, pair<int, int>> pb)
{
    return pa.second.first < pb.second.first;
}

int main()
{
    int n;
    if (!(cin >> n)) return 0;
    vector<pair<int, pair<int, int>>> vx, vy;

    int loop;
    for (loop = 1; loop <= n; loop++)
    {
        pair<int, pair<int, int>> x;
        cin >> x.first;
        x.second.first = loop;
        vx.push_back(x);
    }
    sort(vx.begin(), vx.end(), cmp);

    for (loop = 1; loop <= n; loop++)
    {
        pair<int, pair<int, int>> y;
        cin >> y.first;
        y.second.first = loop;
        vy.push_back(y);
    }
    sort(vy.begin(), vy.end(), cmp);

    int sz = vx.size();
    for (int i = 0; i < sz; ++i)
    {
        vx[i].second.second = i;
    }

    sort(vx.begin(), vx.end(), cmp2);

    for (int i = 0; i < sz; ++i)
    {
        cout << vy[vx[i].second.second].second.first << "\n";
    }

    return 0;
}
#endif