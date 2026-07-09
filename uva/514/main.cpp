// UVa 514 Rails

#include <iostream>
#include <stack>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
#if 0  // WRONG ANSWER
    int N, tmp, cnt;
    stack<int> s;

    while (1)
    {
        cin >> N;
        if (N == 0)
        {
            break;
        }
            
        s.push(N);

        while (cnt = s.top())
        {
            int isInc = 0, isPrint = 1;
            stack<int> s1;

            while (cnt--)
            {
                cin >> tmp;

                if (tmp == 0)
                {
                    s.push(tmp);
                    isPrint = 0;
                    break;
                }

                if (!s1.empty())
                {
                    if (tmp > s1.top())
                        isInc++;
                    else if (tmp < s1.top())
                        isInc--;
                }

                s1.push(tmp);
            }

            if (isPrint)
            {
                if (abs(isInc) == (N - 1))
                    cout << "Yes\n";
                else
                    cout << "No\n";
            }
            else
            {
                cout << "\n";
            }
        }
    }

#else //COPILOT

    int N;
    stack<int> s;

    while (cin >> N && N)
    {
        while (true)
        {
            int first;
            if ((cin >> first) && (first == 0))
            {
                cout << "\n";
                break;
            }

            vector<int> target(N);
            target[0] = first;
            for (int i = 1; i < N; ++i)
            {
                cin >> target[i];
            }

            stack<int> station;
            int current = 1;
            bool isPossible = true;

            for (int i = 0; i < N; ++i)
            {
                while ((current <= N) && (station.empty() || station.top() != target[i]))
                {
                    station.push(current++);
                }

                if (station.top() == target[i])
                {
                    station.pop();
                }
                else
                {
                    isPossible = false;
                    break;
                }
            }

            cout << (isPossible ? "Yes\n" : "No\n");
        }
    }
#endif 

    return 0;
}