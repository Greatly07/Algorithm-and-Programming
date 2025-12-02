#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    int n;
    scanf("%d", &n);

    int line[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &line[i]);
    }

    qsort(line, n, sizeof(int), compare);

    int testCases;
    scanf("%d", &testCases);
    for (int t = 1; t <= testCases; t++)
    {
        int height;
        scanf("%d", &height);

        // BINARY SEARCH
        int left = 0;
        int right = n - 1;
        int found = -1;
        while (left <= right)
        {
            int middle = ((right - left) / 2) + left;
            int comparison = height - line[middle];
            if (comparison == 0)
            {
                found = middle;
                break;
            }
            else if (comparison < 0)
            {
                right = middle - 1;
            }
            else
            {
                left = middle + 1;
            }
        }

        if (found != -1)
        {
            printf("%d\n", found + 1);
        }
        else
        {
            printf("%d\n", found);
        }
    }

    return 0;
}