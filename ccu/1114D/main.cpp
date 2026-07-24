#include <bits/stdc++.h>
using namespace std;
int a[500010];

// [ Window of size m ]
//       +--------------------------------------+
//       | L (m - k smallest) | R (k largest)   |
//       +--------------------------------------+
//                               ^
//                         *R.begin() = k-th largest
multiset<int> L, R;
int m, n;
unsigned k;
void add(int x)
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

void remove(int x)
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
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    // Phase 1: Build the initial window [0, m - 1]
    for (int i = 0; i < m; ++i)
    {
        add(a[i]);
    }

    cout << *R.begin();

    // Phase 2: Slide the window from [1, m] up to [n - m, n - 1]
    for (int i = m; i < n; ++i)
    {
        remove(a[i - m]);
        add(a[i]);
        cout << " " << *R.begin();
    }

    return 0;
}