#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> even, odd;
    while (n--)
    {
        int t;
        cin >> t;
        if (t % 2 == 0)
        {
            even.push_back(t);
        }
        else
        {
            odd.push_back(t);
        }
    }

    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());
    int sz = even.size();
    for (int i = sz - 1; i > -1; --i)
        cout << even[i] << " ";

    sz = odd.size();
    for (int i = sz - 1; i > -1; --i)
        cout << odd[i] << " ";
    return 0;
}
