#include <bits/stdc++.h>
using namespace std;
#define N (100000)
vector<int> sum(4 * N, 0);
vector<int> lazy(4 * N, 0);

void build(string &s, int node, int l, int r)
{
    if (l == r)
    {
        sum[node] = (s[l - 1] - '0');
        return;
    }

    int mid = l + (r - l) / 2;
    build(s, 2 * node, l, mid);
    build(s, 2 * node + 1, mid + 1, r);
    sum[node] = sum[2 * node] + sum[2 * node + 1];
}

// 0/1 區間翻轉
void push_down(int l, int r, int idx)
{
    if (lazy[idx] == 0)
        return;
    int mid = l + (r - l) / 2;
    sum[idx * 2] = (mid - l + 1) - sum[idx * 2];
    lazy[idx * 2] ^= 1;
    sum[idx * 2 + 1] = (r - mid) - sum[idx * 2 + 1];
    lazy[idx * 2 + 1] ^= 1;
    lazy[idx] = 0;
}

// 區間修改
void update(int node, int l, int r, int ql, int qr)
{
    if (qr < l || r < ql)
    {
        return;
    }

    if (ql <= l && r <= qr)
    {
        lazy[node] ^= 1;
        sum[node] = (r - l + 1) - sum[node];
        return;
    }

    push_down(l, r, node);
    int mid = l + (r - l) / 2;
    update(2 * node, l, mid, ql, qr);
    update(2 * node + 1, mid + 1, r, ql, qr);
    sum[node] = sum[2 * node] + sum[2 * node + 1];
}

// 區間查詢
int query(int node, int l, int r, int ql, int qr)
{
    if (r < ql || qr < l)
    {
        return 0;
    }

    if (ql <= l && r <= qr)
    {
        return sum[node];
    }

    push_down(l, r, node);
    int mid = l + (r - l) / 2;
    int left_ans = query(2 * node, l, mid, ql, qr);
    int right_ans = query(2 * node + 1, mid + 1, r, ql, qr);

    return left_ans + right_ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    if (!(cin >> n >> q))
        return 0;

    string s;
    cin >> s;
    build(s, 1, 1, n);

    for (int i = 0; i < q; ++i)
    {
        int cmd;
        cin >> cmd;
        if (cmd == 1)
        {
            int k, x;
            cin >> k >> x;
            update(1, 1, n, k, x);
        }
        else if (cmd == 2)
        {
            int l, r;
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << "\n";
        }
    }

    return 0;
}