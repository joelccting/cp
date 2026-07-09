#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(const int a, const int b)
{
    return (a > b);
}

typedef struct _element
{
    int priority;
    int isMyjob;
} Element;

int main()
{
    int test, n, m;
    cin >> test;

    while (test--)
    {
        queue<Element> que;
        vector<int> series;
        int time = 0;
        cin >> n >> m;

        while (n--)
        {
            Element e;
            cin >> e.priority;
            if (m-- == 0)
            {
                e.isMyjob = 1;
            }
            else
            {
                e.isMyjob = 0;
            }

            series.push_back(e.priority);
            que.push(e);
        }

        sort(series.begin(), series.end(), cmp);
        /*         for (auto i = 0; i < series.size(); ++i)
                {
                    cout << series[i] << ",";
                }
                cout << "\n"; */

        // cout << series[0];

        for (unsigned long long  i = 0; i < series.size(); ++i)
        {
            // cout << series[i] << "\n";
            Element e1 = que.front();
            // cout << e1.priority << "," << e1.isMyjob << "\n";
            while (e1.priority != series[i])
            {
                que.pop();
                que.push(e1);
                e1 = que.front();
                // cout << e1.priority << "," << e1.isMyjob << "\n";
            }

            if (e1.isMyjob == 0)
            {
                que.pop();
                time++;
            }
            else
            {
                break;
            }
        }

        cout << time + 1 << "\n";
    }

    return 0;
}