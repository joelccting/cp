#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL fish(vector<int> &v, LL time, int target)
{
    int sz = v.size();
    LL cnt = 0;
    // for (int i = 0; i < sz; ++i)
    for (auto i : v) //C++11
    {
        cnt += time / v[i];
        if (cnt >= target)
            return target; // Prevent potential 64-bit overflow
    }
    return cnt;
}

LL getTime(vector<int> &v, LL right, int target)
{
    LL left = 1, mid;

    while (left < right)
    {
#if 0
        // cout << "(" << left << "," << right << ")\n";
        mid = left + (right - left) / 2;
        int d1 = fish(v, mid) - target;
        int d2 = fish(v, mid - 1) - target;
        if (d1 == 0 || d1 * d2 < 0)
        {
            break;
        }

        if (d1 > 0 && d2 > 0)
        {
            right = mid;
        }
        else if (d1 < 0 && d2 < 0)
        {
            left = mid;
        }
#endif
        mid = left + (right - left) / 2;
        LL f = fish(v, mid, target);
        if (f >= target)
        {
            right = mid;
        }
        else if (f < target)
        {
            left = mid + 1;
        }
    }

    return left;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    LL k;
    cin >> n >> k;
    vector<int> v;
    while (n--)
    {
        int t;
        cin >> t;
        v.push_back(t);
    }

    sort(v.begin(), v.end());
    LL maxTime = k * v[0];

    // cout << "maxTime=" << maxTime << "\n";
    cout << getTime(v, maxTime, k);
    return 0;
}