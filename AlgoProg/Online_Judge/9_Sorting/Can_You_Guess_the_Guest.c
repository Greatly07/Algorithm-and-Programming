#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
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

        qsort(bag, 25, sizeof(int), compare);

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