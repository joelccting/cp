// permutation
#include <bits/stdc++.h>
using namespace std;

void perm(int pos, int sz, vector<int> &arr, vector<bool> &used, vector<int> &ans)
{
    if (pos == sz)
    {
        for (auto val : ans)
        {
            cout << val << " ";
        }

        cout << "\n";
        return;
    }

    for (int i = 0; i < sz; ++i)
    {
        if (used[i] == false)
        {
            used[i] = true;
            ans[pos] = arr[i];
            perm(pos + 1, sz, arr, used, ans);
            used[i] = false;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; ++i)
    {
        arr.push_back(i + 1);
    }
#if 0 // C++
    do {
        for (int val : arr)
        {
            cout << val << " ";
        }
        cout << "\n";
    } while (next_permutation(arr.begin(), arr.end()));
#else
    vector<bool> used(n, false);
    vector<int> ans(n);
    perm(0, n, arr, used, ans);
#endif
    return 0;
}