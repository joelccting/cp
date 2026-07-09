// a121. 質數又來囉

#include <stdio.h>

int isPrime(int n)
{
    for (int i = 2; i * i <= n; ++i)
    {
        if (0 == n % i)
            return 0;
    }
    return 1;
}

int main()
{
    int a, b;
    while (scanf("%d %d", &a, &b))
    {
        if (a == b)
        {
            printf("0\n");
            continue;
        }

        int cnt = 0;
        for (int i = a; i <= b; ++i)
        {
            if (isPrime(i)) cnt++;
        }
        printf("%d\n", cnt);
        scanf("%*[\r\n]");
    }
    return 0;
}