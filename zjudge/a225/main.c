/* a225. 明明愛排列
 */

#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    int aa = *(int *)a;
    int bb = *(int *)b;

    int diga = aa % 10, digb = bb % 10;
    int tena = aa / 10, tenb = bb / 10;
    if (diga != digb)
    {
        return diga > digb;
    }
    else
    {
        return tena < tenb;
    }
}

int main()
{
    int n, i;
    int a[1000];

    while (scanf("%d", &n) != EOF)
    {
        for (i = 0; i < n; ++i)
        {
            scanf("%d", a + i);
        }

        qsort(a, n, sizeof(int), cmp);

        for (i = 0; i < n; ++i)
        {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
    return 0;
}