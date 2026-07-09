#include <stdio.h>

int graph[6][6];
int path[9];

void dfs(int current, int step)
{
    int i, next;

    path[step] = current;

    if (step == 8)
    {
        for (i = 0; i <= 8; i++)
        {
            printf("%d", path[i]);
        }
        printf("\n");
        return;
    }

    for (next = 1; next <= 5; next++)
    {
        if (graph[current][next] == 1)
        {
            // Mark edge as used
            graph[current][next] = graph[next][current] = 0;

            dfs(next, step + 1);

            // Backtrack: Restore the edge for the next possibility
            graph[current][next] = graph[next][current] = 1;
        }
    }
}

void init(void)
{
    /*edge list*/
    int edges[8][2] = {
        {1, 2}, {1, 3}, {1, 5}, {2, 3}, {2, 5}, {3, 4}, {3, 5}, {4, 5}};

    for (int i = 0; i < 8; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        graph[u][v] = graph[v][u] = 1; // Undirected edges
    }
}

int main()
{

    init();

    dfs(1, 0);
    return 0;
}