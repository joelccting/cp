// ZERO JUDGE a013. 羅馬數字

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

/*
 I (1)
 V (5)

 X (10)
 L (50)

 C (100)
 D (500)

 M (1000)
*/

using namespace std;

int toDig(char c)
{
    int ret;

    switch (c)
    {
    case 'M':
        ret = 1000;
        break;
    case 'C':
        ret = 100;
        break;
    case 'D':
        ret = 500;
        break;
    case 'X':
        ret = 10;
        break;
    case 'L':
        ret = 50;
        break;
    case 'I':
        ret = 1;
        break;
    case 'V':
    default:
        ret = 5;
        break;
    }

    return ret;
}

int romeToDig(string s)
{
    int a, b, sum = 0;

    if (s.size() == 1)
    {
        return toDig(s[0]);
    }

    for (size_t i = 0; i < s.size(); ++i)
    {
        a = toDig(s[i]);
        b = ((i + 1 < s.size()) ? toDig(s[i + 1]) : 0);
        if (a < b)
        {
            sum -= a;
        }
        else
        {
            sum += a;
        }
    }
    return sum;
}

void digToRome(int n)
{
    int m;
    char d4[][5] = {"", "M", "MM", "MMM", "MMMM"},
         d3[][5] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
         d2[][5] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
         d1[][5] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

    m = n / 1000;
    if (m)
    {
        cout << d4[m];
        n = n - m * 1000;
    }

    m = n / 100;
    if (m)
    {
        cout << d3[m];
        n = n - m * 100;
    }

    m = n / 10;
    if (m)
    {
        cout << d2[m];
        n = n - m * 10;
    }

    m = n / 1;
    if (m)
    {
        cout << d1[m];
    }

    cout << "\n";
}

int main()
{
    string str, a, b;
    int aa, bb;

    while (getline(cin, str))
    {
        if (str == "#")
        {
            break;
        }

        stringstream ss(str);
        ss >> a;
        ss >> b;

        /*cout << a << "\n";
        cout << b << "\n"; */
        aa = romeToDig(a);
        bb = romeToDig(b);
/*                 cout << aa << "\n";
                cout << bb << "\n";  */
        if (aa == bb)
        {
            cout << "ZERO" << "\n";
        }
        else
        {
            digToRome(abs(aa - bb));
        }
    }

    return 0;
}