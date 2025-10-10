#include <stdio.h>

int main()
{
    int testCases;
    scanf("%d", &testCases);

    for (int t = 1; t <= testCases; t++)
    {
        int n, m, q;
        scanf("%d %d %d", &n, &m, &q);

        int friends[n][m];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d", &friends[i][j]);
            }
        }

        int list[q];
        for (int i = 0; i < q; i++)
        {
            scanf("%d", &list[i]);
        }

        int lights[m];
        for (int i = 0; i < m; i++)
        {
            lights[i] = 0;
        }

        for (int i = 0; i < q; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (friends[list[i] - 1][j] == 1)
                {
                    if (lights[j] == 1)
                    {
                        lights[j] = 0;
                    }
                    else
                    {
                        lights[j] = 1;
                    }
                }
            }
        }

        printf("Case #%d:\n", t);
        for (int i = 0; i < m; i++)
        {
            if (lights[i] == 1)
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
    }

    return 0;
}