#include <stdio.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int t = 1; t <= m; t++)
    {
        int num;
        scanf("%d", &num);

        int left = 0;
        int right = n - 1;
        int found = -1;
        while (left <= right)
        {
            int middle = ((right - left) / 2) + left;
            int compare = num - arr[middle];
            if (compare == 0)
            {
                found = middle + 1;
                right = middle - 1;
            }
            else if (compare < 0)
            {
                right = middle - 1;
            }

            else
            {
                left = middle + 1;
            }
        }

        printf("%d\n", found);
    }

    return 0;
}