// a017. 五則運算
// HOROWITZ section 3.6

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//#define DEBUG
#ifdef DEBUG
#define dbg(fmt, ...) printf("[%d] " fmt, __LINE__, ##__VA_ARGS)
#else
#define dbg(fmt, ...) 
#endif

#define LEN (100)
int stack[LEN + 1];
int top = -1;

void print(const char *s)
{
    printf("%s ", s);
    printf("Print stack:\n");
    for (int i = 0; i <= top; ++i)
        printf("%d,", stack[i]);
    printf("\n");
}

void push(int x)
{
    if (top < LEN)
    {
        stack[++top] = x;
    }
    // print(__func__);
}

int pop()
{
    int ret;

    if (top > -1)
    {
        ret = stack[top--];
    }
    // print(__func__);
    return ret;
}

enum
{
    PLUS = -1,
    MINUS = -2,
    MUL = -3,
    DIV = -4,
    MOD = -5,
    LPAREN = -6,
    RPAREN = -7
};

int eval(int *d)
{
    for (int i = 0; d[i] != 0; ++i)
    {
        if (d[i] < 0)
        {
            int op2 = pop();
            int op1 = pop();

            switch (d[i])
            {
            case PLUS:
                push(op1 + op2);
                break;
            case MINUS:
                push(op1 - op2);
                break;
            case MUL:
                push(op1 * op2);
                break;
            case DIV:
                push(op1 / op2);
                break;
            case MOD:
                push(op1 % op2);
                break;
            default:
                printf("Warning: op=%d\n", d[i]);
            }
        }
        else
        {
            push(d[i]);
        }
    }

    return pop();
}

// Determine operator precedence
int precedence(int x)
{
    if (x == LPAREN)
        return 0;
    if (x == PLUS || x == MINUS)
        return 1;
    if (x == MUL || x == DIV || x == MOD)
        return 2;

    return 0;
}

void infixToPostfix(int *infix, int *postfix)
{
    int j = 0;
    for (int i = 0; infix[i] != 0; i++)
    {
        int token = infix[i];

        if (token > -1)
        {
            postfix[j++] = token;
            continue;
        }

        if (token == LPAREN)
        {
            push(token);
            continue;
        }

        if (token == RPAREN)
        {
            int x;
            while ((x = pop()) != LPAREN)
            {
                postfix[j++] = x;
            }
            continue;
        }

        // Operator (+, -, *, /, %)
        while (top != -1 && precedence(stack[top]) >= precedence(token))
        {
            postfix[j++] = pop();
        }
        push(token);
    }

    while (top != -1)
    {
        postfix[j++] = pop();
    }
    postfix[j] = 0;
}

int isOp(char *p)
{
    if (*p == '+')
        return PLUS;
    if (*p == '-')
        return MINUS;
    if (*p == '*')
        return MUL;
    if (*p == '/')
        return DIV;
    if (*p == '%')
        return MOD;
    if (*p == '(')
        return LPAREN;
    if (*p == ')')
        return RPAREN;

    return atoi(p);
}

int main()
{
    // int d[] = {2, 3, 4, MUL, PLUS};
    int d[LEN]; // = {2, PLUS, 3, MUL, 4, 0};
    int r[LEN];
    int i;

    char buf[LEN + 1] = {0};
    while (fgets(buf, LEN, stdin) != NULL)
    {
        buf[strcspn(buf, "\n")] = 0;
        char *p = strtok(buf, " ");
        i = 0;
        while (p)
        {
            d[i] = isOp(p);
            // printf("%d:%d\n", i, d[i]);
            ++i;
            p = strtok(NULL, " ");
        }
        // printf("\ni=%d\n", i);

        d[i] = 0;

#ifdef DEBUG
        i = 0;
        while (d[i])
        {
            printf("%d:%d\n", i, d[i]);
            ++i;
        }
        printf("\n");
#endif

        infixToPostfix(d, r);
#ifdef DEBUG
        i = 0;
        while (r[i])
        {
            printf("%d,", r[i++]);
        }
        printf("\n");
#endif

        top = -1;
        printf("%d\n", eval(r));
        scanf("%*[\r\n]");
    }
    return 0;
}