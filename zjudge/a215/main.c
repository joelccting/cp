/*a215. 明明愛數數
 */

#include <stdio.h>

int main()
{
    int n, m;
    int i;
    int sum;
    int cnt;

    while (scanf("%d%d", &n, &m) != EOF)
    {
        sum = 0;
        cnt = 0;
        for (i = n; ; ++i)
        {
            cnt++;
            sum += i;
            if (sum > m)
                break;
        }

        printf("%d\n", cnt);
    }
    return 0;
}