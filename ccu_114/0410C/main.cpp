#include <bits/stdc++.h>
using namespace std;
typedef struct
{
    int a; // 開始日
    int b; // 結束日
    int p; // 小確幸數值
} Event;

typedef long long LL;
#define max(x, y) (((x) < (y)) ? (y) : (x))
vector<Event> e(200050);
LL dp[200050]; // 前 i 個活動中所能獲得的最大小確幸

void f(int n)
{
    vector<int> ends(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        ends[i] = e[i].b;
    }

    for (int i = 1; i <= n; ++i)
    {
        auto it = lower_bound(ends.begin() + 1, ends.begin() + n + 1, e[i].a);
        int j = distance(ends.begin(), it) - 1;
        dp[i] = max(dp[i - 1],       // 不選第 i 個活動
                    dp[j] + e[i].p); // 選第 i 個活動
    }

    cout << dp[n];
}

int cmp(const Event &a, const Event &b)
{
    return a.b < b.b;
}

int main()
{
    int n;
    if (!(cin >> n))
        return 0;

    for (int i = 1; i <= n; ++i)
    {
        cin >> e[i].a >> e[i].b >> e[i].p;
    }

    sort(e.begin() + 1, e.begin() + n + 1, cmp);
    f(n);

    return 0;
}