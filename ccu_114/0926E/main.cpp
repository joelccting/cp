#include <iostream>
typedef unsigned long long ULL;
using namespace std;
ULL n[90];

char getch(ULL N, ULL K)
{
    if (N == 1)
        return 'A';
    if (N == 2)
        return 'C';

    if (K <= n[N - 2])
    {
        return getch(N - 2, K);
    }

    return getch(N - 1, K - n[N - 2]);
}

int main()
{
    ULL Q, N, K;

    n[1] = n[2] = 1;
    for (int i = 3; i < 87; ++i)
    {
        n[i] = n[i - 2] + n[i - 1];
    }

    cin >> Q;
    while (Q--)
    {
        cin >> N >> K;

        cout << getch(N, K) << endl;
    }
    return 0;
}