#include <stdio.h>

#define ll long long

int main()
{
    int testCases;
    scanf("%d", &testCases);

    for (int t = 1; t <= testCases; t++)
    {
        int n;
        ll m;
        scanf("%d %lld", &n, &m);

        ll arr[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &arr[i]);
        }

        int left = 0, right = 0;
        ll sum = 0;
        int segment = -1;
        while (right < n)
        {
            sum += arr[right];

            while (sum > m)
            {
                sum -= arr[left];
                left++;
            }

            if (right - left + 1 > segment && left <= right)
            {
                segment = right - left + 1;
            }

            right++;
        }

        printf("Case #%d: %d\n", t, segment);
    }

    return 0;
}