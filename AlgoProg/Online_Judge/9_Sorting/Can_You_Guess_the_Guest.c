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

    int L[n1], R[n2];

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
    int testCases;
    scanf("%d", &testCases);
    for (int t = 1; t <= testCases; t++)
    {
        int bag[25];
        int sum = 0;
        for (int i = 0; i < 25; i++)
        {
            scanf("%d", &bag[i]);
            sum += bag[i];
        }

        // qsort(bag, 25, sizeof(int), compare);
        mergeSort(bag, 0, 25 - 1);

        int order[5] = {0};
        order[0] = bag[0] / 2;
        order[1] = bag[1] - order[0];
        order[4] = bag[24] / 2;
        order[3] = bag[23] - order[4];
        order[2] = (sum / 10) - (order[0] + order[1] + order[3] + order[4]);

        printf("Case #%d:", t);
        for (int i = 0; i < 5; i++)
        {
            printf(" %d", order[i]);
        }
        printf("\n");
    }

    return 0;
}