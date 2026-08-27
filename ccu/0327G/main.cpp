#include <bits/stdc++.h>
using namespace std;
#define N (500010)
typedef struct
{
    int open;
    int close;
    int match;
} INFO;
vector<int> tree(N << 2);
vector<INFO> info(N << 2);

void pushup(int node)
{
    INFO L = info[node << 1];
    INFO R = info[(node << 1) | 1];
    int new_match = min(L.open, R.close);
    info[node].match = L.match + R.match + new_match;
    info[node].open = L.open + R.open - new_match;
    info[node].close = L.close + R.close - new_match;
}

// 建樹
void build(string &s, int node, int left, int right)
{
    if (left == right)
    {
        tree[left] = s[left - 1];
        if (tree[left] == '(')
        {
            info[node].open = 1;
            info[node].close = 0;
            info[node].match = 0;
        }
        else if (tree[left] == ')')
        {
            info[node].open = 0;
            info[node].close = 1;
            info[node].match = 0;
        }
        return;
    }

    int mid = left + ((right - left) >> 1);
    build(s, node << 1, left, mid);
    build(s, (node << 1) + 1, mid + 1, right);
    pushup(node);
}

// 單點修改
void update(int node, int left, int right, int p)
{
    if (left == p && right == p)
    {
        if (tree[p] == '(')
        {
            tree[p] = ')';
            info[node].open--;
            info[node].close++;
        }
        else if (tree[p] == ')')
        {
            tree[p] = '(';
            info[node].open++;
            info[node].close--;
        }

        return;
    }

    int mid = left + (right - left) / 2;
    if (p <= mid)
    {
        update(node << 1, left, mid, p);
    }
    else
    {
        update((node << 1) + 1, mid + 1, right, p);
    }

    pushup(node);
}

// 區間查詢
INFO query(int node, int left, int right, int qleft, int qright)
{

    if (qleft <= left && right <= qright)
    {
        return info[node];
    }

    INFO left_info = {0, 0, 0};
    INFO right_info = left_info;
    int mid = left + ((right - left) >> 1);
    if (qleft <= mid)
    {
        left_info = query(node << 1, left, mid, qleft, qright);
    }
    if (mid < qright)
    {
        right_info = query((node << 1) + 1, mid + 1, right, qleft, qright);
    }

    int new_match = min(left_info.open, right_info.close);

    INFO ret;
    ret.match = left_info.match + right_info.match + new_match;
    ret.open = left_info.open + right_info.open - new_match;
    ret.close = left_info.close + right_info.close - new_match;
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    if (!(cin >> n >> q))
    {
        return 0;
    }

    string s;
    cin >> s;
    build(s, 1, 1, n);

    for (int i = 0; i < q; ++i)
    {
        int c;
        cin >> c;
        if (c == 1)
        {
            int p;
            cin >> p;
            update(1, 1, n, p);
        }
        else if (c == 2)
        {
            int ql, qr;
            cin >> ql >> qr;
            INFO ans = query(1, 1, n, ql, qr);
            cout << ans.match << "\n";
        }
    }
    return 0;
}