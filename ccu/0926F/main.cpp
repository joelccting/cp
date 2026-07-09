#include <iostream>

using namespace std;
typedef unsigned long long ULL;

int main()
{
    int t, N;
    ULL bloodBar[100010] = {0};
    ULL lives[100010] = {0};

    for (int i = 1; i < 100001; ++i)
    {
        bloodBar[i] = bloodBar[i - 1] + i;
        lives[i] = bloodBar[i] + lives[i - 1];
    }

    cin >> t;
    
    while (t--)
    {
        cin >> N;
        cout << lives[N] << endl;
    }
    return 0;
}