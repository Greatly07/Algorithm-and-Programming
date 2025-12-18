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

    int *line = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &line[i]);
    }

    // qsort(line, n, sizeof(int), compare);
    mergeSort(line, 0, n - 1);

    int max = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int diff = line[i + 1] - line[i];
        if (diff > max)
        {
            max = diff;
        }
    }

    int firstPrint = 1;
    for (int i = 0; i < n - 1; i++)
    {
        int diff = line[i + 1] - line[i];

        if (diff == max)
        {
            if (!firstPrint)
            {
                printf(" ");
            }
            printf("%d %d", line[i], line[i + 1]);
            firstPrint = 0;
        }
    }
    printf("\n");

    free(line);
    return 0;
}