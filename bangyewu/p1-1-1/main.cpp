// P-1-1. 合成函數(1)
#include <bits/stdc++.h>
using namespace std;

// f(x) = 2x - 1
// g(x, y) = x + 2y - 3
int eval()
{
    int x, y;
    char token[7];
    scanf("%s", token);
    if (token[0] == 'f')
    {
        x = eval();
        return 2 * x - 1;
    }
    else if (token[0] == 'g')
    {
        x = eval();
        y = eval();
        return x + 2 * y - 3;
    }
    // else
    // {
    return atoi(token);
    // }
}

int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    cout << eval() << "\n";

    return 0;
}