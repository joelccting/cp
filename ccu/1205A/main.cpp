// 枚舉前兩個數，在剩餘序列中用二分搜尋法查找符合條件的第三個數。
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; ++i)
    {
        int t;
        cin >> t;
        v.push_back(t % 10);
    }

    sort(v.begin(), v.end());
    int sz = v.size();
    int cnt = 0;
    for (int i = 0; i < sz; ++i)
    {
        for (int j = i + 1; j < sz; ++j)
        {
            int target = v[i] + v[j];
            //target = 10 - (target % 10); // WRONG if target is zero or 10, then target turns out to be 10. There is no such a number.
            target = (10 - (target % 10)) % 10;
            // target = (30 - target) % 10; // OR THIS WAY
            bool ret = binary_search(v.begin() + j + 1, v.end(), target);
            if (ret)
            {
                cnt++;
                // cout << i << "," << j << "\n";
            }
        }
    }
    if (cnt != 0)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}