#include <iostream>

using namespace std;

int main()
{
    int i, op, input, result = 0;

    while (cin >> op >> input)
    {
        switch (op)
        {
        case 0:
            result += input;
            break;

        case 1:
            result -= input;
            break;

        case 2:
            result *= input;
            break;

        case 3:
            result /= input;
            break;

        case 4:
            result %= input;
            break;

        default:
            break;
        }
    }

    cout << result;

    return 0;
}
