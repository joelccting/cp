#include <stdio.h>

int main()
{
    int N, M;
    int n, m;
    scanf("%d %d", &N, &M);
    int A[M+1], B[M+1];
    for (int i = 0; i <= M; ++i)
        A[i] = B[i] = 0;

    for (int i = 1; i <= N; ++i)
    {
        scanf(" %d %d", &n, &m);
        ++A[n];
        ++B[m];
    }

    for (int i = 1; i <= M; ++i)
    {
        printf("%d\n", B[i] - A[i]);
    }

    return 0;
}