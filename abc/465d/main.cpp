#include <iostream>
using namespace std;
typedef long long LL;
int main()
{
    int T;
    LL X, Y, K;
    cin >> T;
    while (T--)
    {
        cin >> X >> Y >> K;

        LL x = X, y = Y;
        LL cnt = 0;

        while (x != y)
        {
            if (x > y)
            {
                x /= K;
            }
            else
            {
                y /= K;
            }

            ++cnt;
        }

        cout << cnt << "\n";
    }
    return 0;
}