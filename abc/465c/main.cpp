#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;

    char tmp;
    bool B[N + 1];
    int i;

    B[0] = false;
    for (i = 1; i <= N; ++i)
    {
        cin >> tmp;
        if (tmp == 'o')
            B[i] = !B[i - 1];
        if (tmp == 'x')
            B[i] = B[i - 1];
    }
    vector<int> suffix;
    vector<int> prefix;

    for (i = 1; i < N; ++i)
    {
        if (B[i] == true)
        {
            prefix.push_back(i + 1);
        }
        else
        {
            suffix.push_back(i + 1);
        }
    }

    if (B[N] == false)
    {
        for (i = prefix.size() - 1; i >= 0; --i)
        {
            cout << prefix[i] << " ";
        }
        cout << "1 ";
        for (i = 0; i < suffix.size(); ++i)
        {
            cout << suffix[i] << " ";
        }
    }
    else
    {
        for (i = suffix.size() - 1; i >= 0; --i)
        {
            cout << suffix[i] << " ";
        }
        cout << "1 ";
        for (i = 0; i < prefix.size(); ++i)
        {
            cout << prefix[i] << " ";
        }
    }
    return 0;
}

#if 0 // 26/07/06 brute force failed
void reverse(int b, int e)
{
    while (b < e)
    {
        int tmp = A[b];
        A[b] = A[e];
        A[e] = tmp;
        b++;
        e--;
    }
}

int main()
{
    int N;
    cin >> N;

    char C[N + 1];
    int i;

    for (i = 1; i <= N; ++i)
        cin >> C[i];

    for (i = 1; i <= N; ++i)
        A[i] = i;

    for (i = 1; i <= N; ++i)
    {
        if (C[i] == 'o')
        {
            reverse(1, i);
        }
    }

    for (i = 1; i <= N; ++i)
        cout << A[i] << " ";

    return 0;
}
#endif