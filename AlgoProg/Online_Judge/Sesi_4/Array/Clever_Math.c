#include <stdio.h>

int main()
{
    int testCases;
    scanf("%d", &testCases);

    for (int t = 1; t <= testCases; t++)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        int carry = 0, result = 0, modulo = 10;
        while (a != 0 || b != 0)
        {
            carry = ((a % modulo) + (b % modulo)) % modulo;
            result += carry;
            a -= (a % modulo);
            b -= (b % modulo);
            modulo *= 10;
        }
        printf("Case #%d: %d\n", t, result);
    }
    return 0;
}