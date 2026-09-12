#include <stdio.h>
int main()
{
    int base, height;
    scanf("%d %d", &base, &height);
    printf("Triangle area:%.1f", (float) base * height / 2);
    return 0;
}