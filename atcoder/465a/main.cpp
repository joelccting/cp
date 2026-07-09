#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int A, B;

    cin >> A >> B;
    A *= 3;
    B *= 2;
    if (A > B) cout << "Yes";
    else cout << "No";
    return 0;
}