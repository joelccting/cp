#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct node
{
    int h;
    struct node *next;
} Node;

Node *head;

void print(Node *h)
{
    Node *p = h->next;

    while (p)
    {
        printf("%d\n", p->h);
        p = p->next;
    }
}

void insert(Node *p)
{
    Node *t = head->next;
    Node *prev = head;
    while (t && t->h < p->h)
    {
        prev = t;
        t = t->next;
    }

    prev->next = p;
    p->next = t;
    // print(head);
    ++head->h;
}

void del(int h)
{
    int cnt = 0;
    Node *t = head->next;
    Node *prev = head;

    if (NULL == t) return;

    while (t && t->h <= h)
    {
        prev = t;
        t = t->next;
        ++cnt;
    }

    prev->next = NULL;

    Node *F = head->next;
    while (F)
    {
        Node *tmp = F->next;
        free(F);
        F = tmp->next;
    }

    head->next = t;

    // print(head);

    head->h -= cnt;
}

void release(Node *head)
{
    Node *p = head->next;
    while (p)
    {
        Node *f = p;
        p = p->next;
        free(f);
    }
    free(head);
}
int main()
{
    int Q, c, h;
    assert(1 == scanf("%d", &Q));
    head = (Node *)malloc(sizeof(Node));
    memset(head, 0, sizeof(Node));

    for (int i = 0; i < Q; ++i)
    {
        assert(2 == scanf(" %d %d", &c, &h));
        if (c == 1)
        {
            Node *p = (Node *)malloc(sizeof(Node));
            memset(p, 0, sizeof(Node));
            p->h = h;
            insert(p);
        }
        else if (c == 2)
        {
            del(h);
        }

        printf("%d\n", head->h);
        // for (int i = 1; i < h; ++i)
    }
    release(head);
    return 0;
}