#include <iostream>
#include <cstring>

using namespace std;
typedef long long LL;
char S[500005];

LL sol(int len)
{
    LL ret = 0;
    for (int i = 0; i < len; ++i)
    {
        if (S[i] != 'C') continue;

        int left = i;
        int right = len - i - 1;
        ret += (left <= right ? left : right);
        ret += 1;
    }

    return ret;
}

int main()
{
    cin >> S;
    cout << sol(strlen(S));
    return 0;
}