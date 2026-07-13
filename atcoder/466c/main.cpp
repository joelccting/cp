#include <bits/stdc++.h>
using namespace std;
typedef struct
{
    int i;
    int j;
} Pair;

int main()
{
    int N;
    cin >> N;
    int sz = N * (N - 1) / 2;
    Pair p[sz];
    int idx = 0;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            if (i < j)
            {
                p[idx].i = i;
                p[idx].j = j;
                ++idx;
            }
        }
    }

    int n = 2 * N, cnt = 0;
    idx = 0;
    char ans[10];
    while (n--)
    {
        printf("? %d %d\n", p[idx].i, p[idx].j);
        ++idx;
        fflush(stdout);
        scanf("%s", ans);
        if (0 == strcmp(ans, "Yes"))
            cnt++;
        if (idx >= sz)
            break;
    }
    printf("! %d", cnt);
    return 0;
}