#include <bits/stdc++.h>
using namespace std;

#if 0
typedef struct {
    int time;
    int isArrive;
} Customer;

int cmp(Customer a, Customer b)
{
    return (a.time < b.time);
}

int main()
{
    int n;
    cin >> n;
    vector<Customer> c;
    while (n--)
    {
        Customer a, b;
        cin >> a.time >> b.time;
        a.isArrive = 1;
        b.isArrive = -1;
        c.push_back(a);
        c.push_back(b);
    }
    sort(c.begin(), c.end(), cmp);

    int sz = c.size(), max = 0, sum = 0;
    for (int i = 0; i < sz; ++i)
    {
        sum += c[i].isArrive;
        if (sum > max) max = sum;
    }
    cout << max;
    return 0;
}
#endif // 0

int cmp(pair<int, int> a, pair<int, int> b)
{
    return (a.first < b.first);
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> c;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        pair<int, int> begin = {a, 1}, end = {b, -1};
        c.push_back(begin);
        c.push_back(end);
    }

    sort(c.begin(), c.end(), cmp);
    int sz = c.size(), max = 0, sum = 0;
    for (int i = 0; i < sz; ++i)
    {
        sum += c[i].second;
        if (sum > max)
            max = sum;
    }
    cout << max;
    return 0;
}