#include <stdio.h>

int sum(int trees[], int i, int n)
{
    int result = 0;
    if (i < n)
    {
        result = trees[i] + sum(trees, i + 1, n);
    }

    return result;
}

int main()
{
    int testCases;
    scanf("%d", &testCases);

    for (int t = 1; t <= testCases; t++)
    {
        int n;
        scanf("%d", &n);

        int plantedTrees[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &plantedTrees[i]);
        }

        int result = sum(plantedTrees, 0, n);
        printf("Case #%d: %d\n", t, result);
    }
}