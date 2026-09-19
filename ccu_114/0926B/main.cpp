#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, cmd, parm;
    cin >> N;
    vector<int> vt;
    while (N--)
    {
        cin >> cmd;

        switch (cmd)
        {
        case 1:
            cin >> parm;
            vt.push_back(parm);
            break;
        case 2:
            cin >> parm;
            if (vt.size() == 0)
            {
                cout << "-1" << endl;
            }
            else
            {
                int b = vt.back();
                cout << b << endl;

                if (b == parm)
                {
                    vt.pop_back();
                }
            }
            break;
        case 3:
            if (vt.size() == 0)
            {
                cout << "empty" << endl;
            }
            else
            {
                for (unsigned long long j = 0; j < vt.size(); ++j)
                {
                    cout << vt[j] << " ";
                }
                cout << endl;
            }
            break;
        default:
            break;
        }
    }
    return 0;
}