// a021. 大數運算

#include <stdio.h>
#include <string.h>

#define DEBUG

#if defined(DEBUG)
#define dbg(fmt, ...) printf("[%d] " fmt, __LINE__, ##__VA_ARGS__)
#else
#define dbg(fmt, ...)
#endif

#define LEN (11) //(512)

void init(char *s)
{
    int i, len = strlen(s);
    for (i = len; i < LEN - 1; ++i)
        s[i] = '0';
    s[LEN - 1] = 0;
}

void rev(char *s)
{
    int len = strlen(s);
    dbg("%s\n", s);
    for (int i = 0; i < (LEN - 2) / 2; ++i)
    {
        char t = s[i];
        s[i] = s[LEN - i - 2];
        s[LEN - i - 2] = t;
    }

    dbg("%s\n", s);
}

int adddig(char a, char b, int c, char *res)
{

    int da = a - '0';
    int db = b - '0';
    int r = da + db + c;

    *res = r % 10 + '0';
    dbg("%c + %c = %d\n", a, b, r);
    return r / 10;
}

void add(char *a, char *b, char *res)
{
    int i;
    rev(a);
    rev(b);

    int la = strlen(a);
    int lb = strlen(b);
    int lo = (la > lb ? la : lb);

    // dbg("%d\n", lo);
    int carry = 0;
    for (i = 0; i <= lo; i++)
    {
        char aa = a[i],
             bb = b[i];
        if (0 == a[i])
            aa = '0';
        if (0 == b[i])
            bb = '0';

        if (aa != '0' || bb != '0' || carry != 0)
            carry = adddig(aa, bb, carry, res + i);
    }

    *(res + i) = 0;
    rev(res);
}

int subdig(char a, char b, int c, char *res)
{

    int da = a - '0';
    int db = b - '0';
    int r, ret;

    if (da + c >= db)
    {
        r = da + c - db;
        ret = 0;
    }

    else
    {
        r = da + c + 10 - db;
        ret = -1;
    }

    *res = r + '0';

    return ret;
}

void sub(char *a, char *b, char *res)
{
    int i;
    rev(a);
    rev(b);

    int la = strlen(a);
    int lb = strlen(b);
    int lo = (la > lb ? la : lb);

    // dbg("%d\n", lo);
    int carry = 0;
    for (i = 0; i <= lo; i++)
    {
        char aa = a[i],
             bb = b[i];
        if (0 == a[i])
            aa = '0';
        if (0 == b[i])
            bb = '0';

        if (aa != '0' || bb != '0' || carry != 0)
            carry = subdig(aa, bb, carry, res + i);
    }
    *(res + i) = 0;
    rev(res);
}

int main()
{
    char buf[LEN * 2] = {0}, a[LEN] = {0}, b[LEN] = {0};

    fgets(buf, LEN * 2, stdin);
    buf[strcspn(buf, "\n")] = 0;
    // gets_s(buf, LEN * 2 - 1);

    char *p = strtok(buf, " ");
    int step = 0;
    char op;
    while (p)
    {
        // dbg("%s\n", p);
        switch (step)
        {
        case 0:

            strcpy(a, p);
            init(a);
            step++;
            break;
        case 1:
            op = *p;
            step++;
            break;
        case 2:
        default:

            strcpy(b, p);
            init(b);
            break;
        }

        p = strtok(NULL, " ");
    }

    switch (op)
    {
    case '+':
        add(a, b, buf);
        break;
    case '-':
        sub(a, b, buf);
        break;
    case '*':
        break;
    case '/':
    default:
        break;
    }

    printf("%s", buf);
    return 0;
}