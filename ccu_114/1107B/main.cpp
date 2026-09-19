#include <bits/stdc++.h>
using namespace std;
int bsearch(vector<int> &v, int left, int right, int key)
{
    int sz = v.size();

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (v[mid] == key)
        {
            return mid;
        }
        else if (v[mid] > key)
        {
            right = mid - 1;
        }
        else //if (v[mid] < key)
        {
            left = mid + 1;
        }
    }

    if (right < 0 || (left < sz && v[left] - key < key - v[right]))
        return left;
    return right;
}

int main()
{
    ios::sync_with_stdio(0); // or false
    cin.tie(0);              // or nullptr
    int n, q;
    cin >> n >> q;
    vector<int> v;
    while (n--)
    {
        int t;
        cin >> t;
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    while (q--)
    {
        int t;
        cin >> t;
        int i = bsearch(v, 0, v.size() - 1, t);
        cout << v[i] << " ";
    }
    return 0;
}
