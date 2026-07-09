#include <iostream>

using namespace std;

unsigned long long factorial(unsigned long long x)
{
    if (x == 1) return 1;
    return x * factorial(x - 1);
}

int main()
{
    int N;
    cin >> N;
    cout << factorial(N) << endl;
    return 0;
}