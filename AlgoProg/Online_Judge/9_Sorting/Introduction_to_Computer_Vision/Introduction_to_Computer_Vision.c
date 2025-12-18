#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
    FILE *fp = fopen("testdata.in", "r");
    if (fp == NULL)
    {
        printf("there is no file found");
        return 0;
    }

    int testCases;
    fscanf(fp, "%d", &testCases);
    for (int t = 1; t <= testCases; t++)
    {
        int n, m;
        fscanf(fp, "%d %d", &n, &m);
        int length = n * m;

        int line[length];
        for (int i = 0; i < length; i++)
        {
            fscanf(fp, "%d", &line[i]);
        }

        // qsort(line, length, sizeof(int), compare);
        mergeSort(line, 0, length - 1);

        float medianF;
        if (length % 2 == 0)
        {
            medianF = (line[length / 2] + line[(length / 2) - 1]) / 2.0;
        }
        else
        {
            medianF = line[length / 2];
        }

        int median = (int)round(medianF);

        printf("Case #%d: %d\n", t, median);
    }

    fclose(fp);

    return 0;
}