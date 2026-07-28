#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
    LL n;
    cin >> n;
    LL c50 = 0, c10 = 0, c5 = 0, c1 = 0;
    c50 = n / 50;
    c10 = (n - c50 * 50) / 10;
    c5 = (n - c50 * 50 - c10 * 10) / 5;
    c1 = n - c50 * 50 - c10 * 10 - c5 * 5;
    cout << c50 + c10 + c5 + c1;
    return 0;
}