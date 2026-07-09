/* a813. 4. 城市觀測
 */

#include <stdio.h>
#include <stdlib.h>

// #define DBG

typedef struct pair
{
    int height;
    int count;
} Pair;

typedef long long LL;

void rite(int *arr, LL *ans, int n)
{
    int i, top = -1;
    Pair *stack = (Pair *)calloc(n, sizeof(Pair));

    for (i = n - 1; i > -1; --i)
    {
        /*pop*/
        while (top >= 0 && stack[top].height < arr[i])
        {
            ans[i] += stack[top].count;
            top--;
        }

        if (top >= 0)
        {
            if (stack[top].height == arr[i])
            {
                ans[i] += stack[top].count;
                if (top > 0)
                    ans[i] += 1;
            }
            else
            {
                ans[i] += 1;
            }
        }

        /*push*/
        if (stack[top].height != arr[i])
        {
            stack[++top].height = arr[i];
            stack[top].count = 1;
        }
        else
        {
            ++stack[top].count;
        }

#ifdef DBG
        printf("stack: ");
        for (j = 0; j <= top; ++j)
        {
            printf("(%d, %d) ", stack[j].height, stack[j].count);
        }
        printf("\n");
#endif
    }

    free(stack);
}

void left(int *arr, LL *ans, int n)
{
    int i, top = -1;
    Pair *stack = (Pair *)calloc(n, sizeof(Pair));

    for (i = 0; i < n; ++i)
    {
        /*pop*/
        while (top >= 0 && stack[top].height < arr[i])
        {
            ans[i] += stack[top].count;
            top--;
        }

        if (top >= 0)
        {
            if (stack[top].height == arr[i])
            {
                ans[i] += stack[top].count;
                if (top > 0)
                    ans[i] += 1;
            }
            else
            {
                ans[i] += 1;
            }
        }

        /*push*/
        if (stack[top].height != arr[i])
        {
            stack[++top].height = arr[i];
            stack[top].count = 1;
        }
        else
        {
            ++stack[top].count;
        }

#ifdef DBG
        printf("stack: ");
        for (j = 0; j <= top; ++j)
        {
            printf("(%d, %d) ", stack[j].height, stack[j].count);
        }
        printf("\n");
#endif
    }

    free(stack);
}

int main()
{
    int N, i;
    int *arr;
    LL *ans, sum;

    scanf("%d", &N);

    arr = (int *)calloc(N, sizeof(int));
    ans = (LL *)calloc(N, sizeof(LL));

    for (i = 0; i < N; ++i)
    {
        scanf("%d", arr + i);
    }

#ifdef DBG
    for (i = 0; i < N; ++i)
    {
        printf("%d: %d\n", i, arr[i]);
    }
#endif
    left(arr, ans, N);
    rite(arr, ans, N);
    free(arr);

    sum = 0;
    for (i = 0; i < N; ++i)
    {
        sum += ans[i];
#ifdef DBG
        printf("%d: %lld\n", i, ans[i]);
#endif
    }

    printf("%lld", sum);
    free(ans);

    return 0;
}