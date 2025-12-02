#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
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

        qsort(line, length, sizeof(int), compare);

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