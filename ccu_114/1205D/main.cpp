#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void genSubsetSum(vector<LL> &vl, vector<LL> &v)
{
    unsigned sz = v.size();
    for (unsigned mask = 0; mask < (1U << sz); ++mask)
    {
        LL sum = 0;
        for (unsigned i = 0; i < sz; ++i)
        {
            if (mask & (1U << i))
            {
                sum += v[i];
            }
        }
        vl.push_back(sum);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    LL x;
    if (!(cin >> n >> x))
        return 0;
    vector<LL> v1, v2;
    for (int i = 0; i < n / 2; ++i)
    {
        LL t;
        cin >> t;
        v1.push_back(t);
    }
    for (int i = n / 2; i < n; ++i)
    {
        LL t;
        cin >> t;
        v2.push_back(t);
    }

    vector<LL> vL, vR;
    genSubsetSum(vL, v1);
    genSubsetSum(vR, v2);

    sort(vR.begin(), vR.end());

    LL cnt = 0;
    for (LL val : vL)
    {
        LL target = x - val;
        // Find range of elements equal to 'target' in sorted vR
        auto range = equal_range(vR.begin(), vR.end(), target);
        cnt += (range.second - range.first);
    }

    cout << cnt;

    return 0;
}