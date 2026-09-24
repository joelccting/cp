#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, // N desserts, M drinks
        K;    // K-dollar bills
    if (!(cin >> N >> M >> K))
    {
        return 0;
    }
    LL X,  // 1-dollar bills
        Y; // K-dollar bills

    if (!(cin >> X >> Y))
    {
        return 0;
    }

    vector<LL> A(N + 1, 0); // Dessert i costs Ai dollars,
    vector<LL> B(M + 1, 0); // and drink j costs Bj dollars
    vector<LL> C(M + 1, 0);
    for (int i = 1; i < N + 1; ++i)
    {
        cin >> A[i];
    }
    for (int i = 1; i < M + 1; ++i)
    {
        cin >> B[i];
    }
    sort(A.begin() + 1, A.end());
    sort(B.begin() + 1, B.end());
    for (int i = 2; i < N + 1; ++i)
    {
        A[i] += A[i - 1];
    }
    C[1] = (B[1] + K - 1) / K;
    for (int i = 2; i < M + 1; ++i)
    {
        C[i] = C[i - 1] + (B[i] + K - 1) / K;
    }
    for (int i = 2; i < M + 1; ++i)
    {
        B[i] += B[i - 1];
    }

    vector<LL>::iterator it = upper_bound(C.begin() + 1, C.end(), Y);
    int k = it - C.begin() - 1;
    int ans = INT_MIN;
    for (int i = 0; i <= M; ++i)
    {
        LL x = X, y = Y;
        if (y >= C[i])
        {
            y -= C[i];
            x += C[i] * K - B[i];

            LL remain = y * K + x;
            it = upper_bound(A.begin() + 1, A.end(), remain);
            int d = it - A.begin() - 1;
            ans = max(ans, i + d);
        }
    }
    cout << ans;

    return 0;
}