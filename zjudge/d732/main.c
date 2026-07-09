// ZEROJUDGE d732. 二分搜尋法

#include <stdio.h>

int bsearch(int *a, int key, int lower, int upper)
{
    if (lower > upper)
    {
        return 0;
    }
    
    int mid = (lower + upper) / 2;

    if (a[mid] > key)
    {
        return bsearch(a, key, lower, mid - 1);
    }
    else if (a[mid] < key)
    {
        return bsearch(a, key, mid + 1, upper);
    }

    return mid + 1;
}

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);
    int a[N];
    for (int i = 0; i < N; ++i)
    {
        scanf("%d", a + i);
    }

    int key[K];
    for (int i = 0; i < K; ++i)
    {
        scanf("%d", key + i);
    }

    for (int i = 0; i < K; ++i)
    {
        printf("%d\n", bsearch(a, key[i], 0, N - 1));
    }
    return 0;
}