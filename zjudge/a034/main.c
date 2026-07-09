// a034. 二進位制轉換

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN (300)
char o[10000]; // = {0};
int main()
{
    char buf[LEN] = {0};

    int top = -1, i;
    while (fgets(buf, LEN, stdin) != NULL)
    {
        buf[strcspn(buf, "\n")] = 0;
        int n = atoi(buf);

        while (n)
        {
            if (n & 1)
            {
                o[++top] = '1';
            }
            else
            {
                o[++top] = '0';
            }

            n /= 2;
        }

        for (i = top; i > -1; --i)
            printf("%c", o[i]);
        printf("\n");
        top = -1;
    }
    return 0;
}