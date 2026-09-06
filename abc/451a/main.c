#include <stdio.h>
#include <string.h>

int main()
{
    char s[20];
    scanf("%s", s);
    s[strcspn(s, "\n")] = 0;
    if (strlen(s) % 5 == 0) printf("Yes");
    else printf("No");
    return 0;
}