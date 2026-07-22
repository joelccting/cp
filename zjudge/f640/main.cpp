#include <bits/stdc++.h>
using namespace std;
int eval()
{
    int val;
    if (scanf("%d", &val) == 1)
    {
        return val;
    }

    char F;
    scanf("%c", &F);
    int X, Y, Z;
    switch (F)
    {
    case 'f':
        X = eval();
        return 2 * X - 3;
        break;
    case 'g':
        X = eval();
        Y = eval();
        return 2 * X + Y - 7;
        break;
    case 'h':
    default:
        X = eval();
        Y = eval();
        Z = eval();
        return 3 * X - 2 * Y + Z;
        break;
    }

    return 0;
}

int main()
{
    printf("%d", eval());
    return 0;
}