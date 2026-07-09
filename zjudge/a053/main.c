// a053. Sagit's 計分程式
#include <stdio.h>

int main()
{
    int N, s;
    scanf("%d", &N);

    if (0 <= N && N <= 10)
        s = N * 6;
    else if (11 <= N && N <= 20)
        s = 60 + (N - 10) * 2;
    else if (21 <= N && N <= 40)
        s = 80 + (N - 20) * 1;
    else if (40 < N)
        s = 100;

    printf("%d", s);

    return 0;
}