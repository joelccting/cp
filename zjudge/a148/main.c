/* a148. You Cannot Pass?!
 */

 #include <stdio.h>

 int main()
 {
    int n;
    int i, in;
    double sum;

    while (scanf("%d", &n) != EOF)
    {
        sum = 0;
        for (i = 0; i < n; ++i)
        {
            scanf("%d", &in);
            sum += in;
        }
        sum /= n;
        if (sum > 59) printf("no\n");
        else printf("yes\n");
    }
    return 0;
 }