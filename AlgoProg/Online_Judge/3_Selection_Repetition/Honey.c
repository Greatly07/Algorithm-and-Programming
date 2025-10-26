#include <stdio.h>

int main()
{
    int testCases;
    scanf("%d", &testCases);

    for (int i = 1; i <= testCases; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        int total = a;
        int free = a;
        while (free / b > 0)
        {
            total += free / b;
            free = (free / b) + (free % b);
        }
        printf("Case #%d: %d\n", i, total);
    }

    return 0;
}