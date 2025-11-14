#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
//#include <functional>

using namespace std;

int main()
{
    string sm = "M1kado wins ",  sqq = "qq11123334 wins ";
    int n, tmp, q;

    priority_queue<int> m1;
//    priority_queue<int, vector<int>, greater<int>> qq;
    queue<int> qq;

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> tmp;
        m1.push(tmp);
        qq.push(tmp);
    }

    int cntm1 = 0, cntqq = 0;
    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        int tm1 = m1.top(), tqq = qq.front();
        if (tm1 > tqq)
        {
            ++cntm1;
        }

        if (tm1 < tqq)
        {
            ++cntqq;
        }

        m1.pop();
        qq.pop();
        m1.push(tqq);
        qq.push(tm1);
    }

    if (cntm1 > cntqq)
        cout << "M1kado wins " << cntm1 - cntqq;
    else if (cntm1 < cntqq)
        cout << "qq11123334 wins " << cntqq - cntm1;
    else
        cout << "tie";

    return 0;
}
