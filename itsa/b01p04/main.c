#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char *eng[] = {"dog", "cat", "duck", "cow", "fox"};
    char *ch[] = {"狗", "貓", "鴨", "牛", "狐"};
    char s[80];
    scanf("%s", s);
    int i = 0;
    if (isalpha(s[0]))
    {
        while (strcmp(eng[i], s))
        {
            ++i;
        }
        if (i < 5)
        {
            printf("%s", ch[i]);
        }
    }
    else
    {
        while (strcmp(ch[i], s))
        {
            ++i;
        }
        if (i < 5)
        {
            printf("%s", eng[i]);
        }
    }

    return 0;
}