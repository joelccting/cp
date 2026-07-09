// ZERO JUDGE a054. 電話客服中心

#include <iostream>

using namespace std;

int wcity(int c)
{
    return (c / 10) + 9 * (c % 10);
}

int main()
{
    string str;
    const int city[] = {10, //A
                        11, 12, 13, 14, 15, //BCDEF
                        16, 17, 34, 18, 19, //GHIJK
                        20, 21, 22, 35, 23, //LMNOP
                        24, 25, 26, 27, 28, //QRSTU
                        29, 32, 30, 31, 33};//VWXYZ

    cin >> str;

    int psum = 0;
    for (int i = 0; i < 8; ++i)
    {
        psum += (str[i] - '0') * (8 - i);
    }

    int chksum = str[8] - '0';
    //cout << "chksum= " << chksum << "\n";
    
    for (int i = 0; i < 26; ++i)
    {
        int s = wcity(city[i]) + psum;
        int m = s % 10;
        //if (chksum == (10 - m)) // WRONG!!!
        if ((m + chksum) % 10 == 0)
        {
            cout << (char)(i + 'A');
        }
    }

    return 0;
}