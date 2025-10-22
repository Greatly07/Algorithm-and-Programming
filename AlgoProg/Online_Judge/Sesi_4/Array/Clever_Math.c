#include <stdio.h>

int main()
{
    int testCases;
    scanf("%d", &testCases);

    for (int t = 1; t <= testCases; t++)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        int result, total = 0, modulo = 10;
        while (a != 0 || b != 0)
        {
            result = ((a % modulo) + (b % modulo)) % modulo;
            total += result;
            a -= (a % modulo);
            b -= (b % modulo);
            modulo *= 10;
        }
        printf("Case #%d: %d\n", t, total);
    }
    return 0;
}