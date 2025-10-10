#include <stdio.h>

int main()
{
    int testCases;
    scanf("%d", &testCases);
    for (int t = 1; t <= testCases; t++)
    {
        int n;
        scanf("%d", &n);

        int arr[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }

        int cool_sum = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (arr[j] + arr[k] == arr[i])
                    {
                        cool_sum++;
                        j = n;
                        break;
                    }
                }
            }
        }
        printf("Case #%d: %d\n", t, cool_sum);
    }

    return 0;
}