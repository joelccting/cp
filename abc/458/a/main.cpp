#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char S[35];
    cin >> S;
    cin.ignore();
    int N;
    cin >> N;
    for (int i = N; i < strlen(S) - N; ++i)
    cout << S[i];
    return 0;
}