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

    int *odd = (int *)malloc(n * sizeof(int));
    int counter1 = 0;
    int *even = (int *)malloc(n * sizeof(int));
    int counter2 = 0;

    for (int i = 0; i < n; i++)
    {
        int checker;
        scanf("%d", &checker);
        if (checker % 2 != 0)
        {
            odd[counter1] = checker;
            counter1++;
        }
        else
        {
            even[counter2] = checker;
            counter2++;
        }
    }

    qsort(odd, counter1, sizeof(int), compare);
    qsort(even, counter2, sizeof(int), compare);

    int testCases;
    scanf("%d", &testCases);
    for (int t = 1; t <= testCases; t++)
    {
        int min;
        scanf("%d", &min);

        int oddPair = 0;
        for (int i = 0; i < counter1; i++)
        {
            int tempMin = min - odd[i];

            // BINARY SEARCH
            int left = i + 1;
            int right = counter1 - 1;
            int found = counter1;
            while (left <= right)
            {
                int middle = ((right - left) / 2) + left;
                int comparison = odd[middle] - tempMin;
                if (comparison >= 0)
                {
                    found = middle;
                    right = middle - 1;
                }
                else
                {
                    left = middle + 1;
                }
            }
            oddPair += counter1 - found;
        }

        int evenPair = 0;
        for (int i = 0; i < counter2; i++)
        {
            int tempMin = min - even[i];

            // BINARY SEARCH
            int left = i + 1;
            int right = counter2 - 1;
            int found = counter2;
            while (left <= right)
            {
                int middle = ((right - left) / 2) + left;
                int comparison = even[middle] - tempMin;
                if (comparison >= 0)
                {
                    found = middle;
                    right = middle - 1;
                }
                else
                {
                    left = middle + 1;
                }
            }
            evenPair += counter2 - found;
        }
        printf("Case #%d: %d %d\n", t, oddPair, evenPair);
    }

    free(odd);
    free(even);
    return 0;
}