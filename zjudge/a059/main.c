//ZERO JUDGE a059. 完全平方和

#include <stdio.h>
#include <math.h>

int main()
{
    int T;
    scanf("%d", &T);
    int a, b;

    for (int i = 1; i <= T; ++i)
    {
        int sum = 0;
        scanf("%d", &a);
        scanf("%d", &b);
        int sa = (int) ceil(sqrt(a));
        int asum;
        while ((asum = sa * sa) < b)
        {
            sum += asum;
            ++sa;
        }

        printf("Case %d: %d\n", i, sum);
    }

    return 0;
}