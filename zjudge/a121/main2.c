// a121. 質數又來囉

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define LEN (100000000)

// #define DEBUG
#ifdef DEBUG
#define msg(fmt, ...) printf("%02d " fmt, __LINE__, ##__VA_ARGS__)
#else
#define msg(fmt, ...)
#endif

int segmentedSieve(int a, int b)
{
    int cnt = 0;

    for (int i = a; i <= b; ++i)
    {
        int limit = ceil((int)sqrt(i));
        int test = 0;
        for (int j = 2; j <= limit; ++j)
        {
            if (i % j == 0)
            {
                ++test;
                break;
            }
        }

        if (test == 0)
            ++cnt;
    }

    if (a == 1 || b == 1)
        --cnt;

    return cnt;
}

#if 0
int segmentedSieve(int a, int b)
{
    int sq = (int)sqrt(b);
    bool *prime = (bool *)malloc((sq + 1) * sizeof(bool));
    memset(prime, true, (sq + 1) * sizeof(bool));
    prime[0] = prime[1] = false;

    for (int p = 2; p <= sq; p++)
    {
        if (prime[p])
        {
            for (int i = p * p; i <= sq; i += p)
                prime[i] = false;
        }
    }

    bool *arr = (bool *)malloc((b - a + 2) * sizeof(bool));
    memset(arr, true, (b - a + 2) * sizeof(bool));
    int ret = 0;
    for (int i = 0; i <= sq; ++i)
    {
        if (prime[i])
        {
            int start;
            if (0 == a % i)
                start = 0;
            else
                start = i - a % i;

            for (int j = start; j <= b - a; j += i)
            {
                if (arr[j])
                {
                    arr[j] = false;
                }
            }
        }
    }

    for (int i = 0; i <= b - a; ++i)
    {
        if (arr[i])
        {
            // printf("%d ", i + a);
            ++ret;
        }
    }
    // printf("\n");
    free(arr);
    free(prime);
    return ret;
}
#endif

int main()
{
    int a, b;
    while (scanf("%d %d", &a, &b) != EOF)
    {
        // msg("%d %d\n", a, b);

        if (a > b)
        {
            printf("0\n");
            continue;
        }

        int max = (a >= b)? a : b;
        int min = (a >= b)? b : a;

        printf("%d\n", segmentedSieve(min, max));

        scanf("%*[\r\n]");
    }

    return 0;
}
