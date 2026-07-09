// a104. 排序

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN (11 * 1000)

int cmp(const void *a, const void *b)
{
    return (*(unsigned *)a > *(unsigned *)b);
}

int main()
{
    int n;
    char buf[LEN];
    while (scanf("%d", &n) != EOF)
    {
        unsigned *a = (unsigned *)malloc(n * sizeof(unsigned));
        memset(a, 0, n * sizeof(unsigned));
        scanf("%*[\r\n]");
        fgets(buf, LEN - 1, stdin);
        buf[strcspn(buf, "\n")] = 0;
        char *p = strtok(buf, " ");
        int i = 0;
        while (p)
        {
            a[i++] = atoi(p);
            p = strtok(NULL, " ");
        }

        qsort(a, n, sizeof(unsigned), cmp);

        for (i = 0; i < n; ++i) printf("%d ", a[i]);
        printf("\n");

        free(a);
    }
    return 0;
}