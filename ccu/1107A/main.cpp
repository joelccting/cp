#include <bits/stdc++.h>
using namespace std;
// #define CPP_STYLE
int bsearch(vector<int> &v, int left, int right, int key)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (key == v[mid])
        {
            return mid;
        }
        else if (key > v[mid])
        {
            left = mid + 1;
        }
        else //if (key < v[mid])
        {
            right = mid - 1;
        }
    }

    return -1;
}
int main()
{
#if defined(CPP_STYLE)
    ios::sync_with_stdio(0); // or false
    cin.tie(0);              // or nullptr
#endif
    int n, q;
#if defined(CPP_STYLE)
    cin >> n >> q;
#else
    scanf("%d %d", &n, &q);
#endif
    vector<int> v;
    while (n--)
    {
        int t;
#if defined(CPP_STYLE)
        cin >> t;
#else
        scanf("%d", &t);
#endif
        v.push_back(t);
    }
    // sort(v.begin(), v.end());
    while (q--)
    {
        int t;
#if defined(CPP_STYLE)
        cin >> t;
        cout << bsearch(v, 0, v.size() - 1, t) << " ";
#else
        scanf("%d", &t);
        printf("%d ", bsearch(v, 0, v.size() - 1, t));
#endif
    }
    return 0;
}