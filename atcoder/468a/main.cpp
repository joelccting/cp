#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;
    vector <int> v;
    for (int i = 0; i < N; ++i)
    {
        int a;
        cin >> a;
v.push_back(a);
    }
    int ans = 0;
    for (int i = 1; i < N - 1; ++i)
    {
        if (v[i - 1] < v[i] && v[i + 1] < v[i]) ans++;
    }

    cout << ans;
    return 0;
}