#include <bits/stdc++.h>
using namespace std;
int main()
{
    int X;
    if (!(cin >> X))
    {
        return 0;
    }

    cout << (X + 1) % 3 + 1;
    return 0;
}