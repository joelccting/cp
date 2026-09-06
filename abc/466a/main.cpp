#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, neg = -1;
    cin >> N;
    while (N--)
    {
        int tmp;
        cin >> tmp;
        if (tmp >= 0) neg = 0;
    }
    if (neg == -1) cout << "Yes";
    else cout << "No";
    return 0;
}