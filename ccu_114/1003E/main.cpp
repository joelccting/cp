#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int getWidth(LL x)
{
    if (0 == x)
        return 1;
        
    int cnt = 0;
    while (x)
    {
        x /= 10;
        ++cnt;
    }

    return cnt;
}
int main()
{
    string A, B;
    LL C;
    cin >> A;
    cin >> B;
    int s = A.length();
    int t = B.length();
    C = stoll(A) * stoll(B);
    int n = getWidth(C);
    cout << string(n - s + 1, ' ') << A << "\n";
    cout << "x" << string(n - t, ' ') << B << "\n";
    cout << string(n + 1, '-') << "\n";
    if (1 == t)
    {
        cout << " " << C << "\n";
    }
    else
    {
        int w;
        for (int i = t - 1; i > -1; --i)
        {
            int d = B[i] - '0';
            LL tmp = stoll(A) * d;
            w = getWidth(tmp);
            cout << string(n + 1 - w - (t - 1 - i), ' ');
            cout << tmp << "\n";
        }
        cout << string(n + 1, '-') << "\n";
        w = getWidth(C);
        cout << string(n + 1 - w, ' ');
        cout << C;
    }
    return 0;
}