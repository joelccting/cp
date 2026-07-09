#include <iostream>
using namespace std;

#define min(x, y) ((x > y) ? y : x)
#define max(x, y) ((x > y) ? x : y)
int main()
{
    int X, Y, L, R, A, B;
    cin >> X >> Y >> L >> R >> A >> B;

#if 0 // 26/07/04
    if ((1 <= A && B <= L) || (R <= A && B <= 23))
        cout << (Y * (B - A));
    else if (L <= A && B <= R)
        cout << (X * (B - A));
    else if (1 <= A && A <= L && L <= B && B <= R)
        cout << (L - A) * Y + (B - L) * X;
    else if (L <= A && A <= R && R <= B && B <= 23)
        cout << (R - A) * X + (B - R) * Y;
    else if (A <= L && R <= B)
        cout << (L - A) * Y + (R - L) * X + (B - R) * Y;
#endif

#if 1 // 26/07/06 better solution
    int x = min(B, R) - max(A, L);
    x = max(0, x);
    int y = B - A - x;
    x *= X;
    y *= Y;
    cout << x + y;
#endif

    return 0;
}