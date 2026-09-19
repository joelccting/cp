#include <bits/stdc++.h>
#include <cstring>

using namespace std;

int main()
{
    string s;
    getline(cin, s);
    int len = s.size();
    for (int i = 0; i < len; ++i)
    {
        cout << s[i];
        if (s[i] == ',' && i < len && s[i + 1] != ' ')
        {
            cout << " ";
        }
    }
    cout << "\n";
    return 0;
}