#include <stdio.h>

int count;
int funct(int k)
{
    if (k > 0 && k % 3 == 0)
    {
        count++;
    }

    if (k >= 5 && k % 5 == 0)
    {
        return k * 2;
    }
    else if (k == 1)
    {
        return 2;
    }
    else if (k == 0)
    {
        return 1;
    }

    int var = funct(k - 1) + k + funct(k - 2) + k - 2;

    return var;
}

int main()
{
    int testCases;
    scanf("%d", &testCases);

    for (int t = 1; t <= testCases; t++)
    {
        int n;
        scanf("%d", &n);

        count = 0;
        int result = funct(n);
        printf("Case #%d: %d %d\n", t, result, count);
    }

    return 0;
}