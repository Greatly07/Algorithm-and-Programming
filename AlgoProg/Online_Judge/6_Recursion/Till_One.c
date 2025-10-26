#include <stdio.h>

int tillOne(int n)
{
    if (n == 1)
    {
        return 1;
    }

    int result = 0;
    if (n % 2 == 1)
    {
        result = tillOne(n - 1) + tillOne(n + 1);
    }
    else if (n % 2 == 0)
    {
        result = tillOne(n / 2);
    }

    return result;
}

int main()
{
    int testCases;
    scanf("%d", &testCases);

    for (int t = 1; t <= testCases; t++)
    {
        int n;
        scanf("%d", &n);

        int result = tillOne(n);
        printf("Case #%d: %d\n", t, result);
    }

    return 0;
}