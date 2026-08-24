#include <bits/stdc++.h>
using namespace std;
#define M (10000100)

void sieve(vector<bool> &is_prime, int upper)
{
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= upper; ++i)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= upper; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 預處理階段（埃氏篩）
    vector<bool> is_prime(M + 1, true);
    vector<int> prime;
    sieve(is_prime, M);
    for (int i = 1; i <= M; ++i)
        if (is_prime[i])
            prime.push_back(i);

    int N;
    if (!(cin >> N))
        return 0;

    for (int i = 0; i < N; ++i)
    {
        int x;
        cin >> x;
        auto it = lower_bound(prime.begin(), prime.end(), x);

        cout << *it << " ";
    }
    return 0;
}