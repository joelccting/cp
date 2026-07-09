//a009. 解碼器

#include <stdio.h>
#include <string.h>

#define LEN (1000)

int main()
{
    char buf[LEN + 1] = {0};
    fgets(buf, LEN, stdin);
    buf[strcspn(buf, "\n")] = 0;
    int K = '1' - '*';
    int len = strlen(buf);

    for (int i = 0; i < len; ++i)
    {
        printf("%c", buf[i] - K);
    }
    return 0;
}