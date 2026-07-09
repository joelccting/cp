// ZEROJUDGE a227. 三龍杯 -> 河內之塔

#include <stdio.h>

void hanoi(int n, char from, char mid, char to)
{
    if (n > 0)
    {
        hanoi(n - 1, from, to, mid);
        printf("Move ring %d from %c to %c\n", n, from, to);
        hanoi(n - 1, mid, from, to);
    }
}

int main()
{
    int N; // 最上方的金盤編號為1，最下方的金盤編號為N

    while (scanf("%d", &N) != EOF)
    {
        hanoi(N, 'A', 'B', 'C');
        printf("\n");
    }

    return 0;
}