#include <bits/stdc++.h>
using namespace std;
int x[200010];

// [ Window of size m ]
//       +--------------------------------------+
//       | L (m - k smallest) | R (k largest)   |
//       +--------------------------------------+
//                               ^
//                         *R.begin() = k-th largest
multiset<int> L, R;
void add(int x, int k)
{
    if (R.size() < k || x >= *R.begin())
    {
        R.insert(x);
    }
    else
    {
        L.insert(x);
    }

    // Balance if R became too large
    if (R.size() > k)
    {
        auto it = R.begin();
        L.insert(*it);
        R.erase(it);
    }
}

void remove(int x, int k)
{
    auto it = R.find(x);
    if (it != R.end())
    {
        R.erase(it);
    }
    else
    {
        L.erase(L.find(x));
    }

    // Balance if R became too small
    if (R.size() < k && !L.empty())
    {
        auto it = prev(L.end());
        R.insert(*it);
        L.erase(it);
    }
}

int main()
{
    int n, k, kth;
    cin >> n >> k;

    kth = k / 2 + 1;

    int count = n;
    for (int i = 0; i < n; ++i)
    {
        cin >> x[i];
    }

    // Phase 1: Build the initial window [0, kth - 1]
    for (int i = 0; i < k; ++i)
    {
        add(x[i], kth);
    }
    cout << *R.begin();

    // Phase 2: Slide the window from [1, m] up to [n - m, n - 1]
    for (int i = k; i < n; ++i)
    {
        remove(x[i - k], kth);
        add(x[i], kth);
        cout << " " << *R.begin();
    }
    return 0;
}