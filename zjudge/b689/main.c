// ZEROJUDGE b689

#include <stdio.h>
#include <stdbool.h>

//#define DEBUG

#ifdef DEBUG
#define dbg(fmt, ...) printf("[%d] " fmt, __LINE__, ##__VA_ARGS__)
#else
#define dbg(fmt, ...)
#endif

#define SZ (25)

bool isEdge(int x, int y, int N, int M)
{
    if (x == 0 || x == M - 1)
        return true;
    if (y == 0 || y == N - 1)
        return true;

    return false;
}

void print(char (*s)[SZ], int N, int M)
{
    dbg("Print:\n");
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            printf("%c", s[i][j]);
        }
        printf("\n");
    }
}

bool isPath(char (*s)[SZ], int x, int y, int M, int N)
{
    if ((1 <= x && x <= M) && (1 <= y && y <= N) && (s[x][y] == '.'))
        return true;

    return false;
}

void maze(char (*s)[SZ], int x, int y, int M, int N, int *endX, int *endY)
{
    dbg("%d,%d\n", x, y);

    *endX = x;
    *endY = y;
    s[x][y] = '#';
#ifdef DEBUG
    print(s, M, N);
#endif

    if (isPath(s, x + 1, y, M, N))
        maze(s, x + 1, y, M, N, endX, endY);

    if (isPath(s, x - 1, y, M, N))
        maze(s, x - 1, y, M, N, endX, endY);

    if (isPath(s, x, y - 1, M, N))
        maze(s, x, y - 1, M, N, endX, endY);

    if (isPath(s, x, y + 1, M, N))
        maze(s, x, y + 1, M, N, endX, endY);
}

int main()
{
    char s[25][25] = {0};
    int N,    // row
        M,    // columns
        x, y; /* point coordinate */
    int startX, startY, endX, endY;

    scanf("%d %d", &N, &M);
    // while (getchar() != '\n');
    for (int i = 0; i < N; ++i)
    {
        scanf("%*[\r\n]");
        for (int j = 0; j < M; ++j)
        {
            scanf("%c", &s[i][j]);

            if (s[i][j] == '.' && isEdge(i, j, M, N))
            {
                startX = i;
                startY = j;
            }
        }
    }

#ifdef DEBUG
    print(s, N, M);
#endif
    dbg("start: %d %d", startX, startY);
    maze(s, startX, startY, M, N, &endX, &endY);
    printf("%d %d", endX + 1, endY + 1);
    return 0;
}