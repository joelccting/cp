// ZEROJUDGE b938. kevin 愛殺殺

#if 1 //////////////////// Using array /////////////////////////

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int sn;
    int next;
} Node;

void init(Node *head, int n)
{
    for (int i = 1; i <= n - 1; ++i)
    {
        head[i].sn = i;
        head[i].next = i + 1;
    }
    head[n].sn = n;
    head[n].next = -1;
}

void print(Node *head)
{
    Node *p = head + 1;
    while (-1 != p->next)
    {
        printf("%d,", p->sn);
        p = head + p->next;
    }

    printf("%d\n", p->sn);
}

void del(Node *h, int k)
{
    int k1 = h[k].next;
    if (-1 != k1)
    {
        h[k].next = h[k1].next;
        h[k1].next = -1;
        printf("%d\n", k1);
    }
    else
    {
        printf("0u0 ...... ?\n");
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    Node *head = (Node *)malloc(sizeof(Node) * (n + 1));
    init(head, n);
    // print(head);

    while (m--)
    {
        int k;
        scanf("%d", &k);
        del(head, k);
    }

    free(head);
    return 0;
}

#else //////////////////// Using linked list, TLE /////////////////////////

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int sn;
    struct node *next;
} Node;

Node *init(int n)
{
    Node *r = (Node *)malloc(sizeof(Node) * n);
    Node *t1, *t2;
    for (int i = 0; i <= n - 2; ++i)
    {
        t1 = (Node *)(r + i);
        t2 = (Node *)(r + i + 1);
        t1->sn = i + 1;
        t1->next = t2;
    }

    t2 = (Node *)(r + n - 1);
    t2->sn = n;
    t2->next = NULL;

    return r;
}

void print(Node *head)
{
    Node *t = head->next;
    while (NULL != t->next)
    {
        printf("%d,", t->sn);
        t = t->next;
    }

    printf("%d\n", t->sn);
}

void del(Node *head, int m)
{
    Node *p = head->next;
    int done = 0;

    while (p->next != NULL)
    {
        if (p->sn == m)
        {
            Node *t = p->next;
            p->next = t->next;
            printf("%d\n", t->sn);
            done = 1;
            break;
        }

        p = p->next;
    }

    if (0 == done)
    {
        printf("0u0 ...... ?\n");
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    Node *head = (Node *)malloc(sizeof(Node));
    head->next = init(n);

    // print(head);
    while (m--)
    {
        int k;
        scanf("%d", &k);
        del(head, k);
    }

    free(head->next);
    free(head);
    return 0;
}

#endif