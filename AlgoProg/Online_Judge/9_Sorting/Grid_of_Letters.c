#include <stdio.h>
#include <string.h>

int main()
{
    int row, col;
    scanf("%d %d", &row, &col);

    char grid[row][col + 1];
    for (int i = 0; i < row; i++)
    {
        scanf("%s", grid[i]);
    }

    for (int k = 0; k < row; k++)
    {
        // Bubble Sort
        for (int i = 0; i < col - 1; i++)
        {
            for (int j = 0; j < col - 1 - i; j++)
            {
                if (grid[k][j] > grid[k][j + 1])
                {
                    char temp = grid[k][j];
                    grid[k][j] = grid[k][j + 1];
                    grid[k][j + 1] = temp;
                }
            }
        }
    }

    // Bubble Sort 2
    for (int i = 0; i < row - 1; i++)
    {
        for (int j = 0; j < row - 1 - i; j++)
        {
            if (strcmp(grid[j], grid[j + 1]) < 0)
            {
                char temp[col];
                strcpy(temp, grid[j]);
                strcpy(grid[j], grid[j + 1]);
                strcpy(grid[j + 1], temp);
            }
        }
    }

    for (int i = 0; i < row; i++)
    {
        printf("%s\n", grid[i]);
    }

    return 0;
}