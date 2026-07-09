// a058. MOD3

#include <stdio.h>

int main()
{
    int n, t, cnt[3] = {0};
    scanf("%d", &n);

    while (n--)
    {
        scanf(" %d", &t);

        cnt[t % 3]++;
    }

    for (int i = 0; i < 3; ++i)
        printf("%d ", cnt[i]);
    return 0;
}