/* UVa 12207 That is Your Queue
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*#define DEBUG*/
#define LEN (1000)

#if defined(DEBUG)
#define msg(fmt, ...) printf("[%d] " fmt, __LINE__, ##__VA_ARGS__)
#else
#define msg(fmt, ...)
#endif

typedef struct node
{
    int id;
    struct node *prev;
    struct node *next;
} Node;

void init(Node *head, Node *tail, int len)
{
    int i;
    int sz = sizeof(Node);
    Node *new, *prev;

    for (i = 1; i <= len; ++i)
    {
        prev = tail->prev;
        new = (Node *)malloc(sz);
        new->id = i;
        prev->next = new;
        new->prev = prev;
        new->next = tail;
        tail->prev = new;
    }
}

#if defined(DEBUG)
void printall(Node *h, Node *t)
{
    msg("\n");
    Node *p = h->next;

    while (1)
    {
        printf("%d ", p->id);
        if (p->next == t)
            break;
        p = p->next;
    }

    printf("\n");
}

void printrall(Node *h, Node *t)
{
    msg("\n");
    Node *p = t->prev;

    while (1)
    {
        printf("%d ", p->id);
        if (p->prev == h)
            break;
        p = p->prev;
    }

    printf("\n");
}
#endif

void release(Node *head, Node *tail)
{
    Node *p = head->next,
         *next;

    while (p)
    {
        next = p->next;
        head->next = next;
        next->prev = head;
        msg("%d\n", p->id);
        free(p);
        p = next;
        if (p == tail)
            break;
    }
}

void headToTail(Node *h, Node *t)
{
    Node *first = h->next;
    Node *next = first->next;
    Node *last = t->prev;

    printf("%d\n", first->id);
    h->next = next;
    next->prev = h;

    first->next = t;
    first->prev = last;
    last->next = first;
    t->prev = first;
}

void expedite(Node *h, Node *t, int id)
{
    Node *p = h->next;
    Node *prev, *next, *new;

    while (p != t && p->id != id)
    {
        p = p->next;
    }

    if (p == t)
    {
        next = h->next;
        new = (Node *)malloc(sizeof(Node));
        new->id = id;
        new->prev = h;
        new->next = next;
        h->next = new;
        next->prev = new;
    }
    else
    {
        msg("id:%d\n", p->id);
        prev = p->prev;
        next = p->next;
        prev->next = next;
        next->prev = prev;

        prev = h;
        next = h->next;
        p->prev = prev;
        p->next = next;
        next->prev = p;
        h->next = p;
    }
}

int main()
{
    Node *head = (Node *)malloc(sizeof(Node)),
         *tail = (Node *)malloc(sizeof(Node));
    int P, C;
    int loop = 1;
    int i, cnt, min;
    char buf[81] = {0}, cmd[11], arg[11], *pch;

    head->prev = tail->next = NULL;
    head->next = tail;
    tail->prev = head;

    while (scanf(" %d %d", &P, &C) != EOF)
    {
        if (P == 0 && C == 0)
            break;

        min = (P >= LEN) ? LEN : P;
        init(head, tail, min);
        printf("Case %d:\n", loop++);
        for (i = 0; i < C; ++i)
        {
            scanf("%*[\r\n]");
            fgets(buf, 80, stdin);
            buf[strcspn(buf, "\n")] = 0;
            pch = strtok(buf, " ");
            cnt = 0;
            while (pch)
            {
                ++cnt;
                switch (cnt)
                {
                case 1:
                    strncpy(cmd, pch, 10);
                    break;
                default:
                    strncpy(arg, pch, 10);
                    break;
                }
                pch = strtok(NULL, " ");
            }

            if (!strncmp(cmd, "N", 1))
            {
                headToTail(head, tail);
            }
            else if (!strncmp(cmd, "E", 1))
            {
                int n = atoi(arg);
                expedite(head, tail, n);
            }
#if defined(DEBUG)
            printall(head, tail);
            printrall(head, tail);
#endif
        }

        release(head, tail);
        scanf("%*[\r\n]");
    }

    free(head);
    free(tail);

    return 0;
}