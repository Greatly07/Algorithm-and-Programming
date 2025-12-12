#include <stdio.h>

#define ull unsigned long long

ull calcSum(ull n)
{
    ull part1 = n * (n + 1) / 2;

    return (part1 * (2 * n + 1)) / 3;
}

int main()
{
    int testCases;
    scanf("%d", &testCases);
    for (int t = 1; t <= testCases; t++)
    {
        ull num;
        scanf("%llu", &num);

        int left = 1;
        int right = 1500000;
        int found = -1;
        while (left <= right)
        {
            int middle = ((right - left) / 2) + left;
            if (calcSum(middle) >= num)
            {
                found = middle;
                right = middle - 1;
            }
            else
            {
                left = middle + 1;
            }
        }

        printf("Case #%d: %d\n", t, found);
    }

    return 0;
}