#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, t, X;
    cin >> N;
    vector<int> v;

    for (int i = 0; i < N; ++i)
    {
        cin >> t;
        v.push_back(t);
    }

    cin >> X;
    cout << v[X - 1];

    return 0;
}