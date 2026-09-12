#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, X, Y;
    vector<vector<int>> v;

    cin >> N;
    v.resize(N);
    for (int i = 0; i < N; ++i)
    {
        int L;
        cin >> L;
        for (int j = 0; j < L; ++j)
        {
            int tmp;
            cin >> tmp;
            v[i].push_back(tmp);
        }
    }

    cin >> X >> Y;
    cout << v[X - 1][Y - 1];
    return 0;
}