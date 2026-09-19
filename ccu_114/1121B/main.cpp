#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<
    int,                              // Key 的型態
    null_type,                        // Value 的型態 (若當 set 用寫 null_type；當 map 寫映射型態)
    std::less_equal<int>,             // 排序方式 (從小到大) 允許重複
    rb_tree_tag,                      // 樹的底層結構 (指定為紅黑樹)
    tree_order_statistics_node_update // 關鍵！這個 Tag 讓樹支援「排名」與「找第 k 小」
    >
    ordered_multiset;

int main()
{
    int Q;
    cin >> Q;
    ordered_multiset oms;
    while (Q--)
    {
        int op, x, l, r;
        unsigned ord;
        cin >> op;
        if (op == 1)
        {
            cin >> x;
            oms.insert(x);
        }
        else if (op == 2)
        {
            cin >> x;
#if 0 // This FAILS
            auto it = oms.find(x);
            if (it != oms.end())
            {
                oms.erase(it);
            }

#endif
            // 1. Find the 0-based index of the first occurrence of x
            int rank = oms.order_of_key(x);

            // 2. Get the iterator at that rank
            auto it = oms.find_by_order(rank);

            // 3. Verify it actually equals x, then erase by ITERATOR
            if (it != oms.end() && *it == x)
            {
                oms.erase(it);
            }
        }
        else if (op == 3)
        {
            cin >> l >> r;
            //cout << oms.order_of_key(r) - oms.order_of_key(l) << "\n"; // did only [l, r)
            cout << oms.order_of_key(r + 1) - oms.order_of_key(l) << "\n";
        }
        else if (op == 4)
        {
            cin >> ord;
            auto it = oms.find_by_order(ord - 1);
            if (it != oms.end())
            {
                cout << *it << "\n";
            }
        }
    }
    return 0;
}