#include <iostream>
using namespace std;

int main()
{
    int k;
    cin >> k;
    k %= 26;
    for (int i = 0; i < 4; ++i)
    {
        char c;
        cin >> c;
        if (islower(c))
        {
            if (c - k < 'a')
                c += 26;
            c -= k;
        }
        else
        {
            if (c - k < 'A')
                c += 26;
            c -= k;
        }
        printf("%c ", c);
    }

    return 0;
}