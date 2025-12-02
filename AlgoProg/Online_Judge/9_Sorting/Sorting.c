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

    int *line = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &line[i]);
    }

    qsort(line, n, sizeof(int), compare);

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