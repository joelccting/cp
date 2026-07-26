// The Factorial Number System (Factoradic)
#include <bits/stdc++.h>
using namespace std;

int prank(int *arr, int n)
{
    int r = 0;
    int num[n + 1] = {0};
    for (int i = 1; i <= n; ++i)
    {
        num[i] = i;
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        num[arr[i]] = -1;
    }
    return r;
}

int main()
{
    int N;
    cin >> N;
    int P[N], Q[N];
    for (int i = 0; i < N; ++i)
    {
        cin >> P[i];
    }
    for (int i = 0; i < N; ++i)
    {
        cin >> Q[i];
    }

    cout << abs(prank(P, N) - prank(Q, N)) - 1;
    return 0;
}