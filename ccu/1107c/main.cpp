#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string str;
    cin >> str;
    stack<char> s;
    int sz = str.size(), ans = 1;
    for (int i = 0; i < sz; ++i)
    {
        switch (str[i])
        {
        case '(':
        case '[':
        case '{':
            s.push(str[i]);
            break;
        case ')':
            if (!s.empty() && s.top() == '(')
            {
                s.pop();
            }
            else
            {
                ans = 0;
                break;
            }
            break;
        case ']':
            if (!s.empty() && s.top() == '[')
            {
                s.pop();
            }
            else
            {
                ans = 0;
                break;
            }
            break;
        case '}':
            if (!s.empty() && s.top() == '{')
            {
                s.pop();
            }
            else
            {
                ans = 0;
                break;
            }
            break;
        default:
            break;
        }
    }

    if (!s.empty())
    {
        ans = 0;
    }
    cout << ans;
    return 0;
}