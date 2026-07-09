#include <stdio.h>
#include <string.h>
#include <math.h>

#define LEN (1001)

int main()
{
    char N[LEN];
    while (1)
    {
        scanf("%s", N);
        N[strcspn(N, "\n")] = 0;
        if (N[0] == '0')
            break;

        int len = strlen(N);
        int even = 0, odd = 0;
        for (int i = 0; i < len; i += 2)
            even += N[i] - '0';
        for (int i = 1; i < len; i += 2)
            odd += N[i] - '0';

        printf("%s is ", N);
        if (abs(even - odd) % 11 != 0)
            printf("not ");
        printf("a multiple of 11.\n");
    }

    return 0;
}