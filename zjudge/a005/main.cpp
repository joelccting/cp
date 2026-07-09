// ZERO JUDGE a005. Eva 的回家作業

#include <iostream>

using namespace std;

int main()
{
    int t;
    int a[5];
    cin >> t;
    while (t--)
    {
        cin >> a[0] >> a[1] >> a[2] >> a[3];
        if ((a[1] - a[0]) == (a[3] - a[2]))
        {
            a[4] = a[3] * 2 - a[2];
        }
        else if ((a[1] / a[0]) == (a[3] / a[2]))
        {
            a[4] = a[3] * a[3] / a[2] ;
        }

        for (int i = 0; i < 4; ++i)
        {
            cout << a[i] << " ";
        }
        cout << a[4] << "\n";
    }
    return 0;
}