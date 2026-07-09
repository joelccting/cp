// a040. 阿姆斯壯數

#include <stdio.h>
#include <math.h>

int isArm(int a)
{
    int i = a;
    int d = 0;
    while (i)
    {
        ++d;
        i /= 10;
    }

    i = a;
    int sum = 0;
    while (i)
    {
        sum += (int)pow(i % 10, d);
        i /= 10;
    }

    return a == sum;
}

int main()
{
    int n, m;
    int f = 0;
    scanf("%d %d", &n, &m);
    for (int i = n; i <= m; ++i)
    {
        if (isArm(i))
        {
            printf("%d ", i);
            f = 1;
        }
    }

    if (f == 0) printf("none");
    return 0;
}