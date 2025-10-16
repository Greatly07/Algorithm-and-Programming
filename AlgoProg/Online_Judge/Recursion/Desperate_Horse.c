#include <stdio.h>
#include <limits.h>

int checked[8][8];

int horseMove(char x1, char x2, int steps)
{
    int col = x1 - 'A';
    int row = x2 - '1';
    int *checkPtr = &checked[col][row];

    if (steps < *checkPtr)
    {
        *checkPtr = steps;
    }
    else
    {
        return 0;
    }

    int nextCol, nextRow;

    nextCol = col - 2;
    nextRow = row - 1;
    if (nextCol >= 0 && nextCol < 8 && nextRow >= 0 && nextRow < 8)
    {
        horseMove(nextCol + 'A', nextRow + '1', steps + 1);
    }
    nextCol = col - 2;
    nextRow = row + 1;
    if (nextCol >= 0 && nextCol < 8 && nextRow >= 0 && nextRow < 8)
    {
        horseMove(nextCol + 'A', nextRow + '1', steps + 1);
    }
    nextRow = row + 2;
    nextCol = col - 1;
    if (nextCol >= 0 && nextCol < 8 && nextRow >= 0 && nextRow < 8)
    {
        horseMove(nextCol + 'A', nextRow + '1', steps + 1);
    }
    nextRow = row + 2;
    nextCol = col + 1;
    if (nextCol >= 0 && nextCol < 8 && nextRow >= 0 && nextRow < 8)
    {
        horseMove(nextCol + 'A', nextRow + '1', steps + 1);
    }
    nextCol = col + 2;
    nextRow = row + 1;
    if (nextCol >= 0 && nextCol < 8 && nextRow >= 0 && nextRow < 8)
    {
        horseMove(nextCol + 'A', nextRow + '1', steps + 1);
    }
    nextCol = col + 2;
    nextRow = row - 1;
    if (nextCol >= 0 && nextCol < 8 && nextRow >= 0 && nextRow < 8)
    {
        horseMove(nextCol + 'A', nextRow + '1', steps + 1);
    }
    nextRow = row - 2;
    nextCol = col + 1;
    if (nextCol >= 0 && nextCol < 8 && nextRow >= 0 && nextRow < 8)
    {
        horseMove(nextCol + 'A', nextRow + '1', steps + 1);
    }
    nextRow = row - 2;
    nextCol = col - 1;
    if (nextCol >= 0 && nextCol < 8 && nextRow >= 0 && nextRow < 8)
    {
        horseMove(nextCol + 'A', nextRow + '1', steps + 1);
    }

    return 0;
}

int main()
{
    int testCases;
    scanf("%d", &testCases);

    for (int t = 1; t <= testCases; t++)
    {
        char x[3];
        char y[3];
        scanf(" %s %s", x, y);

        if (x[0] == y[0] && x[1] == y[1])
        {
            printf("Case #%d: %d\n", t, 0);
        }
        else
        {
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    checked[i][j] = INT_MAX;
                }
            }
            horseMove(x[0], x[1], 0);

            int finalStep = checked[y[0] - 'A'][y[1] - '1'];
            printf("Case #%d: %d\n", t, finalStep);
        }
    }

    return 0;
}