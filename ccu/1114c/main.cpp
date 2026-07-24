#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    priority_queue<int> M1kado;
    queue<int> qq11123334;
    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        M1kado.push(a);
        qq11123334.push(a);
    }
    int q, sm = 0, sqq = 0;
    cin >> q;
    while (q--)
    {
        int m = M1kado.top();
        M1kado.pop();
        int qq = qq11123334.front();
        qq11123334.pop();
        if (m > qq)
            sm++;
        else if (m < qq)
            sqq++;

        M1kado.push(qq);
        qq11123334.push(m);
    }

    if (sm > sqq)
        cout << "M1kado wins " << sm - sqq << "\n";
    else if (sm < sqq)
        cout << "qq11123334 wins " << sqq - sm << "\n";
    else
        cout << "tie\n";
    return 0;
}