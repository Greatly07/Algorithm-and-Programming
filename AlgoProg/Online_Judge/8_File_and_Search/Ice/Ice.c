#include <stdio.h>

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

        int n;
        fscanf(fp, "%d", &n);

        int arr[n];
        for (int i = 0; i < n; i++)
        {
            fscanf(fp, "%d", &arr[i]);
        }
        int perimeter = ((n * 2) + 2) * 2;
        int area = n * 4;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > 1)
            {
                if (i == 0)
                {
                    perimeter += (arr[i] - 1) * 2 * 2;
                    area += (arr[i] - 1) * 4;
                }
                else if (arr[i] > arr[i - 1])
                {
                    perimeter += ((arr[i] - arr[i - 1]) * 2 * 2);
                    area += (arr[i] - 1) * 4;
                }
                else
                {
                    area += (arr[i] - 1) * 4;
                }
            }
        }
        printf("Case #%d: %d %d\n", t, perimeter, area);
    }
    fclose(fp);

    return 0;
}