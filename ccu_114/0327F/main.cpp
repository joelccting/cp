#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL ans;

void merge(vector<int> &H, int n, int left, int mid, int right, vector<int> &a)
{

    int i = left, idx = left;
    int j = mid + 1;
    while (i <= mid && j <= right)
    {
        if (H[i] <= H[j])
        {
            a[idx++] = H[i++];
        }
        else
        {
            a[idx++] = H[j++];
            ans += (mid - i + 1);
        }
    }

    while (i <= mid)
    {
        a[idx++] = H[i++];
    }
    while (j <= right)
    {
        a[idx++] = H[j++];
    }

    for (int k = left; k <= right; ++k)
    {
        H[k] = a[k];
    }
}

void merge_sort(vector<int> &H, int n, int left, int right, vector<int> &a)
{
    if ((right - left) > 0)
    {
        int mid = left + (right - left) / 2;
        merge_sort(H, n, left, mid, a);
        merge_sort(H, n, mid + 1, right, a);
        merge(H, n, left, mid, right, a);
    }
}

int main()
{
    int n;
    if (!(cin >> n))
    {
        return 0;
    }

    vector<int> H(n + 1);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> H[i];
    }
    merge_sort(H, n, 1, n, a);
    cout << ans;
    return 0;
}