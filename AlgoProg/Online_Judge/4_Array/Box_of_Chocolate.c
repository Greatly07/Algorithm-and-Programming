#include <stdio.h>

int main()
{
    int testCases;
    scanf("%d", &testCases);

    for (int t = 1; t <= testCases; t++)
    {
        int n, m;
        scanf("%d %d", &n, &m);

        int chocolates[n][m];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d", &chocolates[i][j]);
            }
        }

        long long int chocoWeight = 0;
        int max;
        for (int i = 0; i < n; i++)
        {
            max = chocolates[i][0];
            for (int j = 1; j < m; j++)
            {
                if (chocolates[i][j] > max)
                {
                    max = chocolates[i][j];
                }
            }
            chocoWeight += max;
        }

        printf("Case #%d: %lld\n", t, chocoWeight);
    }

    return 0;
}