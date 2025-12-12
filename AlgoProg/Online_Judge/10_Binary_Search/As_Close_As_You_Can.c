#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    long long int arr[n];
    scanf("%lld", &arr[0]);
    for (int i = 1; i < n; i++)
    {
        scanf("%lld", &arr[i]);
        arr[i] += arr[i - 1];
    }

    int testCases;
    scanf("%d", &testCases);
    for (int t = 1; t <= testCases; t++)
    {
        long long int num;
        scanf("%lld", &num);

        int left = 0;
        int right = n - 1;
        int found = -1;
        while (left <= right)
        {
            int middle = ((right - left) / 2) + left;
            if (arr[middle] <= num)
            {
                found = middle + 1;
                left = middle + 1;
            }
            else
            {
                right = middle - 1;
            }
        }

        printf("Case #%d: %d\n", t, found);
    }

    return 0;
}