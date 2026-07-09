//a065. 提款卡密碼

#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    char s[80] = {0};
    
    scanf("%s", s);
    s[strcspn(s, "\n")] = 0;

    int len = strlen(s);
    for (int i = 0; i < len - 1; ++i)
    {
        printf("%d", abs(s[i] - s[i + 1]));
    }

    return 0;
}