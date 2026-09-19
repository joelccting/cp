#include <bits/stdc++.h>
using namespace std;

bool isdigits(string &s)
{
    int len = s.length();
    for (int i = 0; i < len; ++i)
    {
        if (!isdigit(s[i]))
            return false;
    }
    return true;
}

int main()
{
    stringstream ss;
    string s, token;
    int sum = 0;
    getline(cin, s);
    ss << s;
    // cout << ss.str() << "\n";
    while (!ss.eof())
    {
        ss >> token;

        if (true == isdigits(token))
        {
            sum += stod(token);
        }
    }
    cout << sum;
    return 0;
}