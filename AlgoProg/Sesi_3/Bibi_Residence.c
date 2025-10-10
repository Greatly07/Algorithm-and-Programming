#include <stdio.h>

int main()
{
    int testCases;
    scanf("%d", &testCases);

    for (int t = 1; t <= testCases; t++)
    {
        int totalHouse;
        scanf("%d", &totalHouse);

        int height[totalHouse];
        for (int j = 0; j < totalHouse; j++)
        {
            scanf("%d", &height[j]);
        }

        long long int minDiff = 2000000000LL;
        for (int i = 0; i < totalHouse - 1; i++)
        {
            long long int diff = height[i] - height[i + 1];
            if (diff < 0)
            {
                diff = -diff;
            }
            if (diff < minDiff)
            {
                minDiff = diff;
            }
        }
        printf("Case #%d: %lld\n", t, minDiff);
    }

    return 0;
}