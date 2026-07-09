#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M, K;
    cin >> N >> M >> K;
    int S[N + 1] = {0};

    int i = M, id;
    while (i--)
    {
        cin >> id;
        S[id] = M - i;
    }

    i = K;
    while (i--)
    {
        cin >> id;
        if (0 == S[id])
        {
            cout << "-1" << endl;
        }
        else
        {
            cout << S[id] << endl;
        }
    }

    return 0;
}