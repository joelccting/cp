// d166. 反轉表

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN (51)
#define BLEN (1000)

int main()
{
    int i, j, m, last, a[LEN], c[LEN], val;
    char ch;

    while (scanf("%d", &val) != EOF && val != -1)
    {
        memset(a, 0, sizeof(a));
        memset(c, 0, sizeof(c));
        last = 1;
        a[1] = val;
        while (scanf("%d%c", &val, &ch) == 2)
        {
            a[++last] = val;
            if (ch == '\n')
                break;
        }

#if 0
        for (i = 1; i <= last; ++i)
        {
            printf("%d ", a[i]);
        }
        printf("\n");
#endif

        for (i = 1; i <= last; i++)
        {
            int count = a[i];
            int spaces_seen = 0;
            for (j = 1; j <= last; j++)
            {
                if (c[j] == 0)
                { // If slot is empty
                    if (spaces_seen == count)
                    {
                        c[j] = i;
                        break;
                    }

                    spaces_seen++;
                }
            }
        }
#if 1
        for (m = 1; m <= last; ++m)
        {
            printf("%d ", c[m]);
        }
        printf("\n");
#endif
    }

    return 0;
}