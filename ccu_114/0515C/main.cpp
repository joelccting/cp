#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MODULO(1E9 + 7);

void mul(LL a[2][2], LL b[2][2])
{
    LL t[2][2] = {{0, 0}, {0, 0}};
    t[0][0] = a[0][0] % MODULO * b[0][0] % MODULO;
    t[0][0] += a[0][1] % MODULO * b[1][0] % MODULO;
    t[0][0] %= MODULO;
    t[0][1] = a[0][0] % MODULO * b[0][1] % MODULO;
    t[0][1] += a[0][1] % MODULO * b[1][1] % MODULO;
    t[0][1] %= MODULO;
    t[1][0] = a[1][0] % MODULO * b[0][0] % MODULO;
    t[1][0] += a[1][1] % MODULO * b[1][0] % MODULO;
    t[1][0] %= MODULO;
    t[1][1] = a[1][0] % MODULO * b[0][1] % MODULO;
    t[1][1] += a[1][1] % MODULO * b[1][1] % MODULO;
    t[1][1] %= MODULO;
    a[0][0] = t[0][0];
    a[0][1] = t[0][1];
    a[1][0] = t[1][0];
    a[1][1] = t[1][1];
}

void fibonacci(const LL n)
{
    LL exp = n - 1;
    LL a[2][2] = {{1, 1}, {1, 0}};
    LL A[2][2] = {{1, 0}, {0, 1}};
    if (n == 0)
    {
        cout << "0";
        return;
    }

    if (n == 1)
    {
        cout << "1";
        return;
    }

    while (exp)
    {
        if (exp & 1)
        {
            mul(A, a);
        }

        mul(a, a);
        exp >>= 1;
    }

    cout << A[0][0];
}

int main()
{
    LL n;
    if (!(cin >> n))
        return 0;

    fibonacci(n);
    return 0;
}