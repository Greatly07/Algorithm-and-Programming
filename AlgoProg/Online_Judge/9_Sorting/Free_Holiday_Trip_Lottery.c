#include <stdio.h>
#include <stdlib.h>

/*
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
*/

void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] < R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = ((right - left) / 2) + left;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
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

    // qsort(odd, counter1, sizeof(int), compare);
    // qsort(even, counter2, sizeof(int), compare);
    mergeSort(odd, 0, counter1 - 1);
    mergeSort(even, 0, counter2 - 1);

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