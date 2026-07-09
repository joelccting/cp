// ZERO JUDGE a022

#include <stdio.h>
#include <string.h>

#define STRLEN (1001)
char str2[STRLEN] = {0};
int i = 0;

void reverse(char *a)
{
    if (*(a + 1))
    {
        reverse(a + 1);
    }

    // printf("%c", *a);
    str2[i++] = *a;
}

int main()
{
    char str[STRLEN] = {0};

    scanf("%s", str);
    int len = strlen(str), cnt = 0;

    reverse(str);
    // printf("%s\n", str2);

    for (int i = 0; i < len; ++i)
    {
        if (str[i] == str2[i])
        {
            cnt++;
        }
        else
        {
            break;
        }
    }

    if (len == cnt)
    {
        printf("yes");
    }
    else
    {
        printf("no");
    }
    return 0;
}