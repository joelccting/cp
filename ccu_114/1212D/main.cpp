#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
    int x, n;
    if (!(cin >> x >> n))
        return 0;

#if 0
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    priority_queue<int, vector<int>, greater<int>> pq(v.begin(), v.end());
#else
    priority_queue<LL, vector<LL>, greater<LL>> pq;
    for (int i = 0; i < n; ++i)
    {
        LL t;
        cin >> t;
        pq.push(t);
    }
#endif
    LL sum = 0;
    while (pq.size() != 1)
    {
        LL t = pq.top();
        pq.pop();
        t += pq.top();
        pq.pop();
        pq.push(t);
        sum += t;
    }

    cout << sum;
    return 0;
}