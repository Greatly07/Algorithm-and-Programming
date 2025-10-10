#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int matrix[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (matrix[i][j] == matrix[i][k])
                {
                    printf("Nay\n");
                    return 0;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (matrix[j][i] == matrix[k][i])
                {
                    printf("Nay\n");
                    return 0;
                }
            }
        }
    }

    printf("Yay\n");
    return 0;
}