#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N))
    {
        return 0;
    }

    int c[3] = {0, 0, 0};
    for (int i = 0; i < N; ++i)
    {
        char d[10];
        cin >> d;
        int len = strlen(d);
        int M = 1;

        if (len < 4)
        {
            M = 1000;
        }
        else
        {
            for (int j = 0; j < len; ++j)
            {
                M *= 10;
            }
        }

        int diff = M - atoi(d);
        c[0] += diff % 10;
        diff /= 10;
        c[1] += diff % 10;
        diff /= 10;
        c[2] += diff % 10;
    }

    cout << c[0] << " " << c[1] << " " << c[2];
    return 0;
}