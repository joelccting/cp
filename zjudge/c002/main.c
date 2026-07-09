// c002. 10696 - f91

#include <stdio.h>

int f91(int n)
{
    if (n <= 100)
        return f91(f91(n + 11));

    return (n - 10);
}
int main()
{
    int N;
    while (scanf("%d", &N) && (N != 0))
    {
        printf("f91(%d) = %d\n", N, f91(N));
    }

    return 0;
}