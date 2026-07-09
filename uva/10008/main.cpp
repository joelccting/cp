#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef struct
{
    char c;
    int cnt;
} LETTER;

int cmp(const void *a, const void *b)
{
    LETTER *aa = (LETTER *)a;
    LETTER *bb = (LETTER *)b;
    if (aa->cnt < bb->cnt)
        return 1;
    else if (aa->cnt == bb->cnt)
        return 0;
    return -1;
}

int main()
{
    int n;
    LETTER c[26];
    char b[260];
    cin >> n;
    cin.ignore();
    for (int i = 0; i < 26; ++i)
    {
        c[i].c = i + 'A';
        c[i].cnt = 0;
    }
    
    while (n--)
    {
        memset(b, 0, sizeof(char) * 260);
        cin.getline(b, 256);
        cout << b << endl;
        for (int i = 0; i < strlen(b); ++i)
        {
            char ch = toupper(b[i]);
            if ('A' <= ch && ch <= 'Z')
            {
                ++c[ch - 'A'].cnt;
            }
        }
    }

    qsort(c, 26, sizeof(LETTER), cmp);

    for (int i = 0; i < 26; ++i)
    {
        if (c[i].cnt == 0)
            break;

        cout << c[i].c << " " << c[i].cnt << endl;
    }

    return 0;
}