#include <iostream>
#include <vector>

using namespace std;
typedef unsigned long long ULL;

int main()
{
    ULL K, N, L;
    cin >> N >> K;
    vector<vector<int>> A(N);
    vector<int> c;

    for (ULL i = 0; i < N; ++i)
    {
        cin >> L;
        for (ULL j = 0; j < L; ++j)
        {
            int tmp;
            cin >> tmp;
            A[i].push_back(tmp);
        }
    }

    for (ULL i = 0; i < N; ++i)
    {
        int tmp;
        cin >> tmp;
        c.push_back(tmp);
    }

    ULL i;
    for (i = 0; i < N; ++i)
    {
        // cout << i << ": " << "size: " << A[i].size() << "c: " << c[i] << endl;
        if (K > A[i].size() * c[i])
        {
            K -= A[i].size() * c[i];
            continue;
        }
        else
        {
            break;
        }
    }

    K %= A[i].size();
    // cout << "i=" << i << ", K=" << K << endl;
    cout << A[i][(K + A[i].size() - 1) % A[i].size()];

    return 0;
}