#if 0 // by Gemini
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Helper function to handle interactive queries
bool ask(int L, int R)
{
    cout << "? " << L << " " << R << endl; // endl automatically flushes the buffer
    string response;
    cin >> response;
    return response == "Yes";
}

int main()
{
    // Optimize standard I/O streams (can still use endl for flushing)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n))
        return 0;

    long long ans = 0;
    int R = 1;

    for (int L = 1; L <= n; ++L)
    {
        // The right pointer cannot be behind the left pointer
        R = max(R, L);

        // Expand the right pointer as long as the pair is close
        while (R + 1 <= n && ask(L, R + 1))
        {
            R++;
        }

        // Count the number of valid pairs with 'l' as the left element
        ans += (R - L);
    }

    // Output the final answer
    cout << "! " << ans << endl;

    return 0;
}

#else

#include <bits/stdc++.h>
using namespace std;

bool ask(int L, int R)
{
    char s[10];
    printf("? %d %d\n", L, R);
    fflush(stdout);
    scanf("%s", s);
    return (0 == strcmp(s, "Yes"));
}

int main()
{
    int N;
    long long ans = 0;
    cin >> N;
    int R = 1;
    for (int L = 1; L < N; ++L)
    {
        R = ((R > L) ? R : L); // max(R, L)
        while ((R + 1 <= N) && ask(L, R + 1))
        {
            R++;
        }
        ans += (R - L);
    }
    printf("! %lld\n", ans);
    fflush(stdout);
    return 0;
}

#endif