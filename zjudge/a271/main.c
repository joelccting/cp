#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN (500000)

int main()
{
    int tests;
    char s[LEN];

    scanf("%d", &tests);
    while (getchar() != '\n')
        ;

    while (tests--)
    {
        int dead = 0;
        int poisoned = 0;
        int x, y, z, w, n, m;

        scanf("%d%d%d%d%d%d", &x, &y, &z, &w, &n, &m);
        int weight = m;
        while (getchar() != '\n')
            ;

        fgets(s, LEN + 10, stdin);
        s[strcspn(s, "\n")] = 0;
        if (strlen(s) == 0)
        {
            printf("%dg\n", m);
            continue;
        }

        char *p = strtok(s, " ");
        while (p)
        {
            /*Gemini checked it for me*/
            weight -= n * poisoned;
            /*Gemini checked it for me*/
            if (weight <= 0)
            {
                dead = 1;
                break;
            }

            int ca = atoi(p);
            // printf("%d ", atoi(p));
            switch (ca)
            {
            case 1:
                weight += x;
                break;
            case 2:
                weight += y;
                break;
            case 3:
                weight -= z;
                break;
            case 4:
                weight -= w;
                ++poisoned;
                break;
            case 0:
            default:
                break;
            }

            // printf("%d ", weight);
            if (weight <= 0)
            {
                dead = 1;
                break;
            }
            p = strtok(NULL, " ");
        }

        // printf("\n");

        if (dead)
        {
            printf("bye~Rabbit\n");
        }
        else
        {
            printf("%dg\n", weight);
        }
    }

    return 0;
}