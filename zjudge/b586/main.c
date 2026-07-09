// ZEROJUDGE b586. 文章壓縮

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node
{
    char *word;
    struct node *next;
} Node;

void move(Node *h, Node *prev, Node *curr)
{
    Node *p = curr;
    prev->next = p->next;

    Node *first = h->next;
    p->next = first;
    h->next = p;
}

int search(Node *h, char *s)
{
    Node *prev = h,
         *curr = h->next;
    int sn = 0;
    while (NULL != curr)
    {
        ++sn;
        if (!strcmp(curr->word, s))
        {
            break;
        }

        prev = curr;
        curr = curr->next;
    }

    if (NULL == curr)
    {
        return -1;
    }

    // printf("[%d] %d:%s\n", __LINE__, sn, s);
    move(h, prev, curr);
    return sn;
}

void insert(Node *h, char *s)
{
    int len = strlen(s) + 1;
    Node *p = (Node *)malloc(sizeof(Node));
    p->word = (char *)malloc(len);
    memset(p->word, 0, len);
    strcpy(p->word, s);
    Node *np = h->next;
    p->next = np;
    h->next = p;
}

// void print(Node *h)
// {
//     Node *p = h->next;
//     while (p)
//     {
//         printf("%s ", p->word);
//         p = p->next;
//     }
// }

void destroy(Node *h)
{
    Node *p = h->next;
    while (NULL != p)
    {
        h->next = p->next;
        free(p->word);
        free(p);
        p = h->next;
    }

    free(h);
}

int main()
{
    char ibuf[1001], word[51];
    // char obuf[1001] = {0};
    Node *head = (Node *)malloc(sizeof(Node));
    head->next = NULL;

    // while (scanf("%[^\n]", ibuf))
    while (fgets(ibuf, 1001, stdin))
    {
        if (!strncmp(ibuf, "0", 1))
        {
            break;
        }
#if 0
        const char *delim = " -,'";
        char *pch = strtok(ibuf, delim);
        while (pch)
        {
            // printf("%s\n", pch);
            int v = search(head, pch);
            // int v = 0;
            if (-1 == v)
            {
                // printf("%s ", pch);
                insert(head, pch);
            }

            pch = strtok(NULL, delim);
        }
#endif
        int i = 0, j = 0;
        while (ibuf[i])
        {
            if (isalpha(ibuf[i]))
            {
                word[j] = ibuf[i];
                ++i;
                ++j;
            }
            else
            {
                if (0 != j)
                {
                    word[j] = 0;
                    // printf("[%d] %s\n", __LINE__, word);
                    int v = search(head, word);
                    if (-1 == v)
                    {
                        printf("%s", word);
                        // strcat(obuf, word);
                        insert(head, word);
                    }
                    else
                    {
                        // char num[80];
                        printf("%d", v);
                        // sprintf(num, "%d", v);
                        // strcat(obuf, num);
                    }

                    j = 0;
                }

                // char punc[80];
                printf("%c", ibuf[i++]);
                // sprintf(punc, "%c", ibuf[i++]);
                // strcat(obuf, punc);
            }
        }
    }

    // print(head);
    // printf("%s", obuf);

    destroy(head);

    return 0;
}