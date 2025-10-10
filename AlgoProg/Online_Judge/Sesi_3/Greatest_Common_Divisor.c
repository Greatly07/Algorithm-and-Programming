#include <stdio.h>

int gcd(int a, int b)
{
    while (b)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main()
{
    int testCases;
    scanf("%d", &testCases);

    for (int i = 1; i <= testCases; i++)
    {
        int n;
        scanf("%d", &n);

        int result;
        scanf("%d", &result);

        for (int j = 1; j < n; j++)
        {
            int num;
            scanf("%d", &num);
            result = gcd(result, num);
        }
        printf("Case #%d: %d\n", i, result);
    }

    return 0;
}