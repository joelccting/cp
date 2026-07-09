/* a149. 乘乘樂
 */

#include <stdio.h>
#include <string.h>

int main()
{
    int T, i, j;
    long long prd, t;
    char b[32];

    scanf("%d", &T);
    for (i = 0; i < T; ++i)
    {
        scanf("%s", b);
        b[strcspn(b, "\n")] = 0;

        prd = 1;
        for (j = 0; j < strlen(b); ++j)
        {
            t = b[j] - '0';
            prd *= t;
        }

        printf("%lld\n", prd);
    }

    return 0;
}