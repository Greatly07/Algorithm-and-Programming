#include <stdio.h>
#include <string.h>
typedef struct
{
    char data[11];
} Memory;

void merge(Memory arr[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Memory L[n1], R[n2];
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
        if (strcmp(L[i].data, R[j].data) < 0)
        {
            strcpy(arr[k].data, L[i].data);
            i++;
        }
        else
        {
            strcpy(arr[k].data, R[j].data);
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        strcpy(arr[k].data, L[i].data);
        i++;
        k++;
    }
    while (j < n2)
    {
        strcpy(arr[k].data, R[j].data);
        j++;
        k++;
    }
}

void mergeSort(Memory arr[], int left, int right)
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
        int n, m;
        scanf("%d %d", &n, &m);

        Memory oldD[n];
        for (int i = 0; i < n; i++)
        {
            scanf(" %s", oldD[i].data);
        }
        mergeSort(oldD, 0, n - 1);

        Memory newD[m];
        for (int i = 0; i < m; i++)
        {
            scanf(" %s", newD[i].data);
        }
        mergeSort(newD, 0, m - 1);

        int left = 0;
        int right = n - 1;
        // finish binary search
        // while (left <= right)
        // {
        //     int mid = ((right - left) / 2 + left);
        // }
    }
}