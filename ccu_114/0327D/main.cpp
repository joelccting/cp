#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N (100000)
vector<LL> a(N + 1), tree(4 * N);

void build(int node, int l, int r)
{
    if (l == r)
    {
        tree[node] = a[l];
        return;
    }

    int mid = l + (r - l) / 2;
    build(2 * node, l, mid);
    build(2 * node + 1, mid + 1, r);
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}

void modify(int node, int l, int r, int k, int x)
{
    if (l == r)
    {
        tree[node] += x;
        return;
    }
    int mid = l + (r - l) / 2;
    if (k <= mid)
    {
        modify(2 * node, l, mid, k, x);
    }
    else
    {
        modify(2 * node + 1, mid + 1, r, k, x);
    }

    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}

LL query(int node, int l, int r, int ql, int qr)
{
    if (ql <= l && r <= qr)
    {
        return tree[node];
    }

    if (r < ql || l > qr)
    {
        return LLONG_MIN;
    }

    int mid = l + (r - l) / 2;
    LL left_ans = query(2 * node, l, mid, ql, qr);
    LL right_ans = query(2 * node + 1, mid + 1, r, ql, qr);

    return max(left_ans, right_ans);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    if (!(cin >> n >> q))
        return 0;

    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }

    build(1, 1, n);
    for (int i = 0; i < q; ++i)
    {
        int cmd;
        cin >> cmd;
        if (cmd == 1)
        {
            int k, x;
            cin >> k >> x;
            modify(1, 1, n, k, x);
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