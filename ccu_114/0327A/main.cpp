// 分治法（Divide and Conquer）
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef struct
{
    LL x;
    LL y;
} Point;

bool cmpy(const Point &p1, const Point &p2)
{
    return p1.y < p2.y;
}

LL getShortestDistance(int from, int to, vector<Point> &v)
{
    LL dx, dy;
    if (from == to)
        return LLONG_MAX;

    if (from + 1 == to)
    {
        dx = v[to].x - v[from].x;
        dx *= dx;
        dy = v[to].y - v[from].y;
        dy *= dy;
        return dx + dy;
    }

    int mid = (from + to) / 2;

    LL dL = getShortestDistance(from, mid, v);
    LL dR = getShortestDistance(mid + 1, to, v);
    LL d = min(dL, dR);

    vector<Point> strip;
    for (int i = from; i <= to; ++i)
    {
        LL t = v[i].x - v[mid].x;
        t *= t;
        if (d > t)
            strip.push_back({v[i].x, v[i].y});
    }

    sort(strip.begin(), strip.end(), cmpy);
    int sz = strip.size();
    for (int i = 0; i < sz; ++i)
    {
        for (int j = i + 1; j < sz; ++j)
        {
            LL sdy = strip[i].y - strip[j].y;
            sdy *= sdy;
            if (sdy >= d)
            {
                break;
            }
            else
            {
                LL sdx = strip[i].x - strip[j].x;
                sdx *= sdx;
                d = min(d, sdx + sdy);
            }
        }
    }

    return d;
}

bool cmp(const Point &p1, const Point &p2)
{
    if (p1.x != p2.x)
        return p1.x < p2.x;
    return p1.y < p2.y;
}

int main()
{
    int n;
    if (!(cin >> n))
        return 0;
    vector<Point> v;
    for (int i = 0; i < n; ++i)
    {
        LL x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }

    sort(v.begin(), v.end(), cmp);
    int sz = v.size();
    cout << getShortestDistance(0, sz - 1, v);

    return 0;
}