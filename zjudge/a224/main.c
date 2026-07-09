/* a224. 明明愛明明
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LEN (1010)

int main()
{
    char b[LEN];
    int a[26] = {0}, i, odd, even;

    while (scanf("%s", b) != EOF)
    {
        b[strcspn(b, "\n")] = 0;
        memset(a, 0, sizeof(a));
        for (i = 0; i < strlen(b); ++i)
        {
            if (isalpha(b[i]))
            {
                a[tolower(b[i]) - 'a']++;
            }
        }

        odd = even = 0;
        for (i = 0; i < 26; ++i)
        {
            if (a[i] & 1)
                odd++;
            else
                even++;
        }

#if 0
        for (i = 0; i < 26; ++i)
            printf("%d ", a[i]);
        printf("\n");
#endif

        if (odd > 1)
            printf("no...\n");
        else
            printf("yes !\n");
    }

    return 0;
}